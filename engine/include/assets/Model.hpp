#pragma once

#include <memory>
#include <vector>

#include "graphics/Mesh.hpp"

namespace onux {

class ModelScene;

class Model {
public:
    using Ptr    = std::unique_ptr<const Model>;
    using Meshes = std::vector<Mesh::Ptr>;

public:
    static Ptr create(const ModelScene* modelScene);

public:
    ~Model();
    const Meshes& getMeshes() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;

    explicit Model(const ModelScene* modelScene);
};

} // namespace onux
