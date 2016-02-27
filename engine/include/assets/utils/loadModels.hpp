#pragma once

#include "utils/UniqueMap.hpp"

namespace onux {

class Model;
class ModelScene;

UniqueMap<Model> loadModels(const UniqueMap<ModelScene>& modelScenes);

} // namespace onux
