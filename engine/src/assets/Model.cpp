#include "assets/Model.hpp"

#include "exceptions/validators/validateNotNull.hpp"
#include "resources/ModelScene.hpp"

namespace onux {

struct Model::Impl {
    const Meshes meshes;

    explicit Impl(const ModelScene* modelScene);
};

auto Model::create(const ModelScene* modelScene) -> Ptr {
    validateNotNull("modelScene", "Model::create", modelScene);
    return Ptr(new Model(modelScene));
}

Model::Model(const ModelScene* modelScene)
    : impl(new Impl(modelScene)) {}

Model::~Model() {}

auto Model::getMeshes() const -> const Meshes& {
    return impl->meshes;
}

// Implementation

static Model::Meshes loadMeshes(const ModelScene* modelScene) {
    Model::Meshes meshes;

    modelScene->forEachMesh([&](const aiMesh* mesh) {
        meshes.push_back(Mesh::create(mesh));
    });

    return meshes;
}

Model::Impl::Impl(const ModelScene* modelScene)
    : meshes(loadMeshes(modelScene)) {}

} // namespace onux
