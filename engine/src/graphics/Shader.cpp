#include "graphics/Shader.hpp"

#include <vector>
#include <string>
#include <memory>

#include "gl/ShaderProgram.hpp"
#include "gl/ShaderObject.hpp"
#include "resources/containers/ShaderSources.hpp"
#include "graphics/interfaces/IShaderFile.hpp"
#include "graphics/interfaces/IShaderObjectData.hpp"

using std::string;
using std::vector;
using std::unique_ptr;
using std::move;

namespace onux {

struct Shader::Impl {
    const ShaderProgram shaderProgram;

    Impl(const IShaderFile& shaderFile, const ShaderSources& shaderSources);
};

Shader::Shader(const IShaderFile& shaderFile, const ShaderSources& shaderSources)
    : impl(new Impl(shaderFile, shaderSources)) {}

Shader::~Shader() {}

const ShaderProgram& Shader::getProgram() const {
    return impl->shaderProgram;
}

// Implementation

static const ShaderObject::Sources getSources(
    const IShaderObjectData& shaderObjectData,
    const ShaderSources&     shaderSources
) {
    const string& type = shaderObjectData.getType();
    ShaderObject::Sources sources;

    for (const string& sourcePath : shaderObjectData.getSourcePaths()) {
        sources.push_back(shaderSources[sourcePath + "." + type]);
    }

    return sources;
}

static const ShaderProgram::Objects getObjects(
    const IShaderFile&   shaderFile,
    const ShaderSources& shaderSources
) {
    ShaderProgram::Objects objects;

    shaderFile.forEachShaderObjectData([&](const IShaderObjectData& shaderObjectData) {
        objects.emplace_back(new ShaderObject(getSources(
            shaderObjectData,
            shaderSources
        )));
    });

    return objects;
}

Shader::Impl::Impl(const IShaderFile& shaderFile, const ShaderSources& shaderSources)
    : shaderProgram(getObjects(shaderFile, shaderSources)) {}

} // namespace onux
