#include "assets/Model.hpp"

using std::move;

namespace onux {

struct Model::Impl {
    const Meshes meshes;
};

auto Model::create(Meshes meshes) -> Ptr {
    return Ptr(new Model(meshes));
}

Model::Model(Meshes& meshes)
    : impl(new Impl { move(meshes) }) {}

Model::~Model() {}

void Model::forEachMesh(MeshCB meshCB) const {
    for (const Mesh::Ptr& mesh : impl->meshes) {
        meshCB(mesh.get());
    }
}

} // namespace onux
