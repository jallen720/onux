#include "graphics/Scene.hpp"

#include <sstream>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/Importer.hpp>

#include "exceptions/subsystemErrors/AssimpError.hpp"
#include "exceptions/argErrors/EmptyStringArg.hpp"

using std::string;
using std::stringstream;
using Assimp::Importer;

namespace onux {

struct Scene::Impl {
    Importer       importer;
    const aiScene* scene;
    const Meshes   meshes;

    Impl(const string& path);
};

static void validatePath(const string& path) {
    if (path.empty()) {
        throw EmptyStringArg("path", "Scene");
    }
}

static const string getValidPath(const string& path) {
    validatePath(path);
    return path;
}

Scene::Scene(const string& path)
    : impl(new Impl(getValidPath(path))) {}

Scene::~Scene() {}

const Scene::Meshes& Scene::getMeshes() const {
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

static const Scene::Meshes loadMeshes(const aiScene* scene) {
    Scene::Meshes meshes;

    for (auto i = 0u; i < scene->mNumMeshes; i++) {
        meshes.push_back({ scene->mMeshes[i] });
    }

    return meshes;
}

Scene::Impl::Impl(const string& path)
    : scene(getValidScene(path, importer))
    , meshes(loadMeshes(scene)) {}

} // namespace onux
