#include "assets/utils/loadShaderPrograms.hpp"

#include "resources/utils/ShaderObjectData.hpp"
#include "resources/Shader.hpp"
#include "resources/ShaderSource.hpp"
#include "gl/ShaderProgram.hpp"
#include "gl/ShaderObject.hpp"

using std::string;

namespace onux {

static const ShaderObject::Sources getSources(
    const string&                        type,
    const ShaderObjectData::SourcePaths& sourcePaths,
    const UniqueMap<ShaderSource>&       shaderSources
) {
    ShaderObject::Sources sources;

    for (const string& sourcePath : sourcePaths) {
        sources.push_back(shaderSources[sourcePath + "." + type]);
    }

    return sources;
}

static const ShaderProgram::Objects getObjects(
    const Shader*                  shader,
    const UniqueMap<ShaderSource>& shaderSources
) {
    ShaderProgram::Objects objects;

    shader->forEachShaderObjectData([&](const ShaderObjectData& shaderObjectData) {
        objects.push_back(ShaderObject::create(getSources(
            shaderObjectData.getType(),
            shaderObjectData.getSourcePaths(),
            shaderSources
        )));
    });

    return objects;
}

UniqueMap<ShaderProgram> loadShaderPrograms(
    const UniqueMap<Shader>&       shaders,
    const UniqueMap<ShaderSource>& shaderSources
) {
    UniqueMap<ShaderProgram> shaderPrograms;

    shaders.forEach([&](const Shader* shader, const string& path) {
        shaderPrograms.add(
            path,
            ShaderProgram::create(getObjects(
                shader,
                shaderSources
            ))
        );
    });

    return shaderPrograms;
}

} // namespace onux
