#pragma once

#include "utils/UniqueMap.hpp"

namespace onux {

class Model;
class ModelScene;
class Texture;
class ShaderProgram;

UniqueMap<Model> loadModels(
    const UniqueMap<ModelScene>&    modelScenes,
    const UniqueMap<ShaderProgram>& shaderPrograms,
    const UniqueMap<Texture>&       textures
);

} // namespace onux
