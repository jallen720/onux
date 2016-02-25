#include "assets/loadShaderPrograms.hpp"

#include "resources/utils/ShaderObjectData.hpp"
#include "resources/Shader.hpp"
#include "resources/ShaderSource.hpp"
#include "gl/ShaderProgram.hpp"
#include "gl/ShaderObject.hpp"

using std::string;

namespace onux {

static const ShaderObject::Sources getSources(
    const ShaderObjectData&        shaderObjectData,
    const UniqueMap<ShaderSource>& sources
) {
    const string& type = shaderObjectData.getType();
    ShaderObject::Sources objectSources;

    for (const string& sourcePath : shaderObjectData.getSourcePaths()) {
        objectSources.push_back(sources[sourcePath + "." + type]);
    }

    return objectSources;
}

static const ShaderProgram::Objects getObjects(
    const Shader*                  shader,
    const UniqueMap<ShaderSource>& sources
) {
    ShaderProgram::Objects objects;

    shader->forEachShaderObjectData([&](const ShaderObjectData& shaderObjectData) {
        objects.push_back(ShaderObject::create(getSources(
            shaderObjectData,
            sources
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
