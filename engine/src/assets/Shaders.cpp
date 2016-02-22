#include "assets/Shaders.hpp"

#include <string>

using std::string;

namespace onux {

static void loadShaders(
    typename UniqueMap<Shader>::ElementMap& shaderMap,
    const Resources<ShaderFile>&            shaderFiles,
    const Resources<ShaderSource>&          shaderSources
) {
    shaderFiles.forEach([&](const ShaderFile* shaderFile, const string& path) {
        shaderMap[path] = Shader::create(shaderFile, shaderSources);
    });
}

Shaders::Shaders(
    const Resources<ShaderFile>&   shaderFiles,
    const Resources<ShaderSource>& shaderSources
) {
    loadShaders(getElementMap(), shaderFiles, shaderSources);
}

} // namespace onux
