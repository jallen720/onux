#include "graphics/utils/getValidAssimpScene.hpp"

#include "exceptions/subsystemErrors/AssimpError.hpp"

using std::string;
using Assimp::Importer;

namespace onux {

static void validateScene(const aiScene* scene, const Importer& importer) {
    if (scene == nullptr) {
        throw AssimpError(importer.GetErrorString());
    }
}

const aiScene* getValidAssimpScene(
    const string&      path,
    Importer&          importer,
    const unsigned int importFlags
) {
    const aiScene* scene = importer.ReadFile(path, importFlags);
    validateScene(scene, importer);
    return scene;
}

} // namespace onux
