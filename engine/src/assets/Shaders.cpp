#include "assets/Shaders.hpp"

#include <stdexcept>

#include "exceptions/Error.hpp"
#include "exceptions/validators/validateNotEmpty.hpp"

using std::string;
using std::out_of_range;

namespace onux {

static void loadShaders(
    typename Shaders::ShaderMap&   shaderMap,
    const Resources<ShaderFile>&   shaderFiles,
    const Resources<ShaderSource>& shaderSources
) {
    shaderFiles.forEach([&](const ShaderFile* shaderFile, const string& path) {
        shaderMap[path] = Shader::create(shaderFile, shaderSources);
    });
}

Shaders::Shaders(
    const Resources<ShaderFile>&   shaderFiles,
    const Resources<ShaderSource>& shaderSources
) {
    loadShaders(m_shaderMap, shaderFiles, shaderSources);
}

const Shader * const Shaders::operator [](const string& path) const {
    validateNotEmpty("path", "Shaders<>::operator[]", path);

    try {
        return m_shaderMap.at(path).get();
    }
    catch (const out_of_range& _) {
        throw Error("No shader found at \"" + path + "\"!");
    }
}

} // namespace onux
