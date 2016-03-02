#include "resources/ModelScene.hpp"

#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/Importer.hpp>

#include "exceptions/validators/validateNotEmpty.hpp"
#include "exceptions/subsystemErrors/AssimpError.hpp"
#include "resources/utils/MeshData.hpp"

using std::string;
using std::vector;
using Assimp::Importer;

namespace onux {

struct ModelScene::Impl {
    Importer        importer;
    const MeshDatas meshDatas;

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

auto ModelScene::getMeshDatas() const -> const MeshDatas& {
    return impl->meshDatas;
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

static ModelScene::MeshDatas getValidMeshDatas(const aiScene* scene) {
    ModelScene::MeshDatas meshDatas;

    for (auto i = 0u; i < scene->mNumMeshes; i++) {
        meshDatas.emplace_back(scene->mMeshes[i], scene);
    }

    return meshDatas;
}

ModelScene::Impl::Impl(const string& path, ImportFlags importFlags)
    : meshDatas(getValidMeshDatas(loadValidScene(
        path,
        importer,
        importFlags
    ))) {}

} // namespace onux
