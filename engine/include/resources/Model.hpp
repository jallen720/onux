#pragma once

#include <memory>
#include <string>
#include <vector>

#include "graphics/Mesh.hpp"

struct aiScene;

namespace onux {

class Model {
public:
    using Ptr    = std::unique_ptr<const Model>;
    using Meshes = std::vector<Mesh::Ptr>;

public:
    static Ptr create(const std::string& path);

public:
    ~Model();
    const Meshes& getMeshes() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;

    explicit Model(const std::string& path);
};

} // namespace onux
