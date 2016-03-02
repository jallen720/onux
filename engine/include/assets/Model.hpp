#pragma once

#include <memory>
#include <vector>
#include <functional>

#include "graphics/Mesh.hpp"

namespace onux {

class Model {
public:
    using Ptr    = std::unique_ptr<const Model>;
    using Meshes = std::vector<Mesh::Ptr>;
    using MeshCB = const std::function<void(const Mesh*)>&;

public:
    static Ptr create(Meshes meshes);

public:
    ~Model();
    void forEachMesh(MeshCB meshCB) const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;

    explicit Model(Meshes& meshes);
};

} // namespace onux
