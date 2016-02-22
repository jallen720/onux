#include "graphics/Shader.hpp"

#include <vector>
#include <string>
#include <memory>

#include "gl/ShaderProgram.hpp"
#include "gl/ShaderObject.hpp"
#include "graphics/ShaderSource.hpp"
#include "graphics/interfaces/IShaderFile.hpp"
#include "graphics/interfaces/IShaderObjectData.hpp"

using std::string;
using std::vector;
using std::unique_ptr;
using std::move;

namespace onux {

struct Shader::Impl {
    const ShaderProgram shaderProgram;

    Impl(const IShaderFile* shaderFile, Sources sources);
};

auto Shader::create(const IShaderFile* shaderFile, Sources sources) -> Ptr {
    return Ptr(new Shader(shaderFile, sources));
}

Shader::Shader(const IShaderFile* shaderFile, Sources sources)
    : impl(new Impl(shaderFile, sources)) {}

Shader::~Shader() {}

const ShaderProgram& Shader::getProgram() const {
    return impl->shaderProgram;
}

// Implementation

static const ShaderObject::Sources getObjectSources(
    const IShaderObjectData& shaderObjectData,
    Shader::Sources          sources
) {
    const string& type = shaderObjectData.getType();
    ShaderObject::Sources objectSources;

    for (const string& sourcePath : shaderObjectData.getSourcePaths()) {
        objectSources.push_back(sources[sourcePath + "." + type]);
    }

    return objectSources;
}

static const ShaderProgram::Objects getObjects(
    const IShaderFile* shaderFile,
    Shader::Sources    sources
) {
    ShaderProgram::Objects objects;

    shaderFile->forEachShaderObjectData([&](const IShaderObjectData& shaderObjectData) {
        objects.emplace_back(new ShaderObject(getObjectSources(
            shaderObjectData,
            sources
        )));
    });

    return objects;
}

Shader::Impl::Impl(const IShaderFile* shaderFile, Sources sources)
    : shaderProgram(getObjects(shaderFile, sources)) {}

} // namespace onux
