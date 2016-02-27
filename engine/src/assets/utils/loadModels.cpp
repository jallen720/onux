#include "assets/utils/loadModels.hpp"

#include <string>

#include "assets/Model.hpp"
#include "resources/ModelScene.hpp"

using std::string;

namespace onux {

UniqueMap<Model> loadModels(const UniqueMap<ModelScene>& modelScenes) {
    UniqueMap<Model> models;

    modelScenes.forEach([&](const ModelScene* modelScene, const string& path) {
        models.add(path, Model::create(modelScene));
    });

    return models;
}

} // namespace onux
