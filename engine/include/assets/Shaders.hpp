#pragma once

#include <map>
#include <string>

#include "resources/Resources.hpp"
#include "resources/files/ShaderFile.hpp"
#include "graphics/ShaderSource.hpp"
#include "graphics/Shader.hpp"

namespace onux {

class Shaders {
public:
    using ShaderMap = std::map<const std::string, typename Shader::Ptr>;

public:
    Shaders(
        const Resources<ShaderFile>&   shaderFiles,
        const Resources<ShaderSource>& shaderSources
    );
    const Shader * const operator [](const std::string& path) const;

private:
    ShaderMap m_shaderMap;
};

} // namespace onux


