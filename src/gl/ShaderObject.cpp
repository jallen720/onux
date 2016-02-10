#include "gl/ShaderObject.hpp"

#include "gl/interfaces/IShaderSource.hpp"
#include "gl/utils/ShaderObjectInfo.hpp"
#include "utils/existsIn.hpp"
#include "utils/toString.hpp"
#include "exceptions/Error.hpp"
#include "exceptions/argErrors/ArgFailedRequirement.hpp"
#include "exceptions/argErrors/InvalidArgProperty.hpp"

namespace onux {

struct ShaderObject::Impl {
    const GLuint           id;
    const ShaderObjectInfo info;

    Impl(const GLuint id);
    void loadSources(const Sources& sources) const;
    void compile() const;
    void validateCompileStatus() const;
    const bool compilationSucceeded() const;
};

static void validateSourceCount(const size_t sourceCount) {
    static const size_t MIN_SOURCE_COUNT = 1;

    if (sourceCount < MIN_SOURCE_COUNT) {
        throw InvalidArgProperty(
            "sources",
            "ShaderObject::ShaderObject",
            "count",
            ">= " + toString(MIN_SOURCE_COUNT)
        );
    }
}

static bool areSameType(const ShaderObject::Sources& sources, const GLenum type) {
    return !existsIn(sources, [&](const IShaderSource* source) {
        return source->getType() != type;
    });
}

static void validateSameType(const ShaderObject::Sources& sources, const GLenum type) {
    if (!areSameType(sources, type)) {
        throw ArgFailedRequirement(
            "sources",
            "ShaderObject::ShaderObject",
            "All sources must be the same type"
        );
    }
}

static const GLuint getValidShaderObject(const ShaderObject::Sources& sources) {
    validateSourceCount(sources.size());
    const GLenum type = sources[0]->getType();
    validateSameType(sources, type);
    return glCreateShader(type);
}

ShaderObject::ShaderObject(const Sources& sources)
    : GLData(getValidShaderObject(sources))
    , impl(new Impl(getID())) {
    impl->loadSources(sources);
    impl->compile();
    impl->validateCompileStatus();
}

ShaderObject::~ShaderObject() {
    glDeleteShader(getID());
}

const GLenum ShaderObject::getType() const {
    return impl->info.getValue(GL_SHADER_TYPE);
}

// Implementation

ShaderObject::Impl::Impl(const GLuint id)
    : id(id)
    , info(
        this->id,
        glGetShaderiv,
        glGetShaderInfoLog
    ) {}

void ShaderObject::Impl::loadSources(const Sources& sources) const {
    const size_t sourceCount = sources.size();
    const GLchar* sourceCode[sourceCount];

    for (size_t i = 0; i < sourceCount; i++) {
        sourceCode[i] = sources[i]->getCode();
    }

    glShaderSource(
        id,
        sourceCount,
        sourceCode,
        nullptr
    );
}

void ShaderObject::Impl::compile() const {
    glCompileShader(id);
}

void ShaderObject::Impl::validateCompileStatus() const {
    if (!compilationSucceeded()) {
        // TODO: Destroy shader here?
        throw Error("ShaderObject compilation failed:\n" + info.getLog());
    }
}

const bool ShaderObject::Impl::compilationSucceeded() const {
    return info.getValue(GL_COMPILE_STATUS) == GL_TRUE;
}

} // namespace onux
