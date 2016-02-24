#pragma once

#include "utils/UniqueMap.hpp"

namespace onux {

class ShaderProgram;
class ShaderFile;
class ShaderSource;

UniqueMap<ShaderProgram>::ElementMap loadShaderPrograms(
    const UniqueMap<ShaderFile>&   shaderFiles,
    const UniqueMap<ShaderSource>& shaderSources
);

} // namespace onux
