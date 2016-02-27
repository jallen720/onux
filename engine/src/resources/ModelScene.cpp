#include "resources/ModelScene.hpp"

#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/Importer.hpp>

#include "exceptions/validators/validateNotEmpty.hpp"
#include "exceptions/subsystemErrors/AssimpError.hpp"
#include "exceptions/Error.hpp"
#include "utils/toString.hpp"

using std::string;
using Assimp::Importer;

namespace onux {

struct ModelScene::Impl {
    Importer       importer;
    const aiScene* scene;

    Impl(const string& path, ImportFlags importFlags);
};

ModelScene::ImportFlags ModelScene::DEFAULT_IMPORT_FLAGS =
    aiProcess_GenSmoothNormals      |
    aiProcess_CalcTangentSpace      |
    aiProcess_Triangulate           |
    aiProcess_JoinIdenticalVertices |
    aiProcess_SortByPType;

auto ModelScene::create(const string& path, ImportFlags importFlags) -> Ptr {
    validateNotEmpty("path", "ModelScene::create", path);
    return Ptr(new ModelScene(path, importFlags));
}

ModelScene::ModelScene(const string& path, ImportFlags importFlags)
    : impl(new Impl(path, importFlags)) {}

ModelScene::~ModelScene() {}

static void validateMeshIndex(const unsigned int index, const unsigned int meshCount) {
    if (index >= meshCount) {
        throw Error(
            "ModelScene::getMesh() index out of range "
            "(mesh count: " + toString(meshCount) + ")"
        );
    }
}

const aiMesh* ModelScene::getMesh(const unsigned int index) const {
    validateMeshIndex(index, impl->scene->mNumMeshes);
    return impl->scene->mMeshes[index];
}

void ModelScene::forEachMesh(MeshCB meshCB) const {
    for (auto i = 0u; i < impl->scene->mNumMeshes; i++) {
        meshCB(impl->scene->mMeshes[i]);
    }
}

// Implementation

static void validateScene(const aiScene* scene, const Importer& importer) {
    if (scene == nullptr) {
        throw AssimpError(importer.GetErrorString());
    }
}

static const aiScene* loadValidScene(
    const string&           path,
    Importer&               importer,
    ModelScene::ImportFlags importFlags
) {
    const aiScene* scene = importer.ReadFile(path, importFlags);
    validateScene(scene, importer);
    return scene;
}

ModelScene::Impl::Impl(const string& path, ImportFlags importFlags)
    : scene(loadValidScene(path, importer, importFlags)) {}

} // namespace onux
