#pragma once

#include "resources/Resources.hpp"
#include "resources/files/ShaderFile.hpp"
#include "resources/ShaderSource.hpp"
#include "graphics/Shader.hpp"
#include "utils/UniqueMap.hpp"

namespace onux {

class Shaders : public UniqueMap<Shader> {
public:
    Shaders(
        const Resources<ShaderFile>&   shaderFiles,
        const Resources<ShaderSource>& shaderSources
    );
};

} // namespace onux


