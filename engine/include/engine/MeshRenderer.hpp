#pragma once

#include <memory>

namespace onux {

class Mesh;

class MeshRenderer {
public:
    explicit MeshRenderer(const Mesh* mesh);
    ~MeshRenderer();
    void render() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
