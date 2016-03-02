#pragma once

#include <memory>
#include <vector>
#include <string>

#include "MACROS/ONUX_MOVE_ONLY_DEFS.hpp"

struct aiMesh;
struct aiScene;

namespace onux {

class MeshData {
public:
    using TexturePaths = std::vector<std::string>;

public:
    MeshData(const aiMesh* mesh, const aiScene* scene);
    ONUX_MOVE_ONLY_DEFS(MeshData)
    const aiMesh* getMesh() const;
    const TexturePaths& getTexturePaths() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
