#pragma once

#include <memory>
#include <string>
#include <vector>
#include "graphics/Mesh.hpp"

struct aiScene;

namespace onux {

class Model {
public:
    typedef std::vector<Mesh> Meshes;

public:
    explicit Model(const std::string& path);
    ~Model();
    const Meshes& getMeshes() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
