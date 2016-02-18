#include "graphics/Model.hpp"

#include "graphics/utils/getValidAssimpScene.hpp"
#include "exceptions/validators/validateNotEmpty.hpp"

using std::string;
using Assimp::Importer;

namespace onux {

struct Model::Impl {
    Importer     importer;
    const Meshes meshes;

    explicit Impl(const string& path);
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

static Model::Meshes loadMeshes(const aiScene* scene) {
    Model::Meshes meshes;

    for (auto i = 0u; i < scene->mNumMeshes; i++) {
        meshes.emplace_back(new Mesh(scene->mMeshes[i]));
    }

    return meshes;
}

Model::Impl::Impl(const string& path)
    : meshes(loadMeshes(getValidAssimpScene(path, importer))) {}

} // namespace onux
