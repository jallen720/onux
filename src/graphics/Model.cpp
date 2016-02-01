#include "graphics/Model.hpp"

#include <sstream>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/Importer.hpp>

#include "exceptions/subsystemErrors/AssimpError.hpp"
#include "exceptions/validators/validateNotEmpty.hpp"

using std::string;
using std::stringstream;
using Assimp::Importer;

namespace onux {

struct Model::Impl {
    Importer       importer;
    const aiScene* scene;
    const Meshes   meshes;

    Impl(const string& path);
};

static const string getValidPath(const string& path) {
    validateNotEmpty("path", "Model::Model", path);
    return path;
}

Model::Model(const string& path)
    : impl(new Impl(getValidPath(path))) {}

Model::~Model() {}

const Model::Meshes& Model::getMeshes() const {
    return impl->meshes;
}

// Implementation

static void validateScene(const aiScene* scene, const Importer& importer) {
    if (scene == nullptr) {
        throw AssimpError(importer.GetErrorString());
    }
}

static const aiScene* getValidScene(const string& path, Importer& importer) {
    static const unsigned int IMPORT_FLAGS =
        aiProcess_GenSmoothNormals      |
        aiProcess_CalcTangentSpace      |
        aiProcess_Triangulate           |
        aiProcess_JoinIdenticalVertices |
        aiProcess_SortByPType;

    const aiScene* scene = importer.ReadFile(path, IMPORT_FLAGS);
    validateScene(scene, importer);
    return scene;
}

static const Model::Meshes loadMeshes(const aiScene* scene) {
    Model::Meshes meshes;

    for (auto i = 0u; i < scene->mNumMeshes; i++) {
        meshes.emplace_back(scene->mMeshes[i]);
    }

    return meshes;
}

Model::Impl::Impl(const string& path)
    : scene(getValidScene(path, importer))
    , meshes(loadMeshes(scene)) {}

} // namespace onux
