#pragma once

#include "utils/UniqueMap.hpp"

namespace onux {

class ShaderProgram;
class Shader;
class ShaderSource;

UniqueMap<ShaderProgram> loadShaderPrograms(
    const UniqueMap<Shader>&       shaders,
    const UniqueMap<ShaderSource>& shaderSources
);

} // namespace onux
