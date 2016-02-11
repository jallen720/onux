#include "gl/ShaderProgram.hpp"

#include <string>
#include <glm/gtc/type_ptr.hpp>

#include "gl/ShaderObject.hpp"
#include "gl/utils/ShaderProgramInfo.hpp"
#include "gl/utils/ValidValues.hpp"
#include "exceptions/Error.hpp"
#include "exceptions/argErrors/ArgFailedRequirement.hpp"
#include "exceptions/argErrors/InvalidArg.hpp"
#include "exceptions/validators/validateNotNull.hpp"
#include "exceptions/validators/validateNotEmpty.hpp"
#include "utils/existsIn.hpp"

#include "MACROS/VALID_VALUE.hpp"

using std::vector;
using std::string;
using glm::value_ptr;
using glm::vec3;
using glm::vec4;
using glm::mat4;

namespace onux {

struct ShaderProgram::Impl {
    using Self = const ShaderProgram*;
    using Processor = void (*)(const GLuint, const GLuint);

    Self                    self;
    const ShaderProgramInfo info;

    explicit Impl(Self self);
    void process(const Objects& objects, Processor processor) const;
    void link() const;
    void validateLinkStatus() const;
    const bool linkingSucceeded() const;
    const GLint getValidUniformLocation(const GLchar* name) const;
};

static const bool hasType(const ShaderProgram::Objects& objects, const GLenum type) {
    return existsIn(objects, [&](const ShaderObject::Ptr& object) {
        return object->getType() == type;
    });
}

static const bool hasRequiredTypes(const ShaderProgram::Objects& objects) {
    // The minimum requirements for a shader program to be created are a vertex shader object and a
    // fragment shader object.
    static const vector<GLenum> REQUIRED_TYPES {
        GL_VERTEX_SHADER,
        GL_FRAGMENT_SHADER,
    };

    return !existsIn(REQUIRED_TYPES, [&](const GLenum requiredType) {
        return !hasType(objects, requiredType);
    });
}

static void validateHasRequiredTypes(const ShaderProgram::Objects& objects) {
    if (!hasRequiredTypes(objects)) {
        throw ArgFailedRequirement(
            "objects",
            "ShaderProgram::ShaderProgram",
            "Must contain atleast 1 vertex & 1 fragment object."
        );
    }
}

static GLuint getValidShaderProgram(const ShaderProgram::Objects& objects) {
    validateHasRequiredTypes(objects);
    return glCreateProgram();
}

ShaderProgram::ShaderProgram(const Objects& objects)
    : GLData(getValidShaderProgram(objects))
    , impl(new Impl(this)) {
    impl->process(objects, glAttachShader);
    impl->link();
    impl->process(objects, glDetachShader);
    impl->validateLinkStatus();
}

ShaderProgram::~ShaderProgram() {
    glDeleteProgram(getID());
}

void ShaderProgram::use() const {
    glUseProgram(getID());
}

static void validateName(const GLchar* name) {
    validateNotNull("name", "ShaderProgram::setUniform", name);
    validateNotEmpty("name", "ShaderProgram::setUniform", name);
}

void ShaderProgram::setUniform(const GLchar* name, const GLint value) const {
    validateName(name);

    glUniform1i(
        impl->getValidUniformLocation(name),
        value
    );
}

void ShaderProgram::setUniform(const GLchar* name, const vec3& value) const {
    validateName(name);

    glUniform3f(
        impl->getValidUniformLocation(name),
        value.x,
        value.y,
        value.z
    );
}

void ShaderProgram::setUniform(const GLchar* name, const vec4& value) const {
    validateName(name);

    glUniform4f(
        impl->getValidUniformLocation(name),
        value.x,
        value.y,
        value.z,
        value.w
    );
}

static void validateTranspose(const GLboolean transpose) {
    static const ValidValues VALID_TRANSPOSE_VALUES({
        VALID_VALUE(GL_TRUE),
        VALID_VALUE(GL_FALSE),
    });

    if (!VALID_TRANSPOSE_VALUES.contains(transpose)) {
        throw InvalidArg(
            "transpose",
            "ShaderProgram::setUniform",
            VALID_TRANSPOSE_VALUES.getNames()
        );
    }
}

void ShaderProgram::setUniform(
    const GLchar*   name,
    const mat4&     value,
    const GLboolean transpose
) const {
    static const GLsizei MATRIX_COUNT = 1;

    validateName(name);
    validateTranspose(transpose);

    glUniformMatrix4fv(
        impl->getValidUniformLocation(name),
        MATRIX_COUNT,
        transpose,
        value_ptr(value)
    );
}

// Implementation

ShaderProgram::Impl::Impl(Self self)
    : self(self)
    , info(
        self->getID(),
        glGetProgramiv,
        glGetProgramInfoLog
    ) {}

void ShaderProgram::Impl::process(const Objects& objects, Processor processor) const {
    for (const ShaderObject::Ptr& object : objects) {
        processor(self->getID(), object->getID());
    }
}

void ShaderProgram::Impl::link() const {
    glLinkProgram(self->getID());
}

void ShaderProgram::Impl::validateLinkStatus() const {
    if (!linkingSucceeded()) {
        throw Error("ShaderProgram linking failed: " + info.getLog());
    }
}

const bool ShaderProgram::Impl::linkingSucceeded() const {
    return info.getValue(GL_LINK_STATUS) == GL_TRUE;
}

static const void validateLocation(const GLint location, const string& name) {
    const static GLint UNKNOWN_LOCATION = -1;

    if (location == UNKNOWN_LOCATION) {
        throw Error("Failed to find location of uniform \"" + name + "\" in ShaderProgram");
    }
}

const GLint ShaderProgram::Impl::getValidUniformLocation(const GLchar* name) const {
    const GLint location = glGetUniformLocation(self->getID(), name);
    validateLocation(location, name);
    return location;
}

} // namespace onux
