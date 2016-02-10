#pragma once

#include <memory>
#include <GL/glew.h>

#include "graphics/Vertex.hpp"
#include "graphics/BufferData.hpp"

struct aiMesh;

namespace onux {

class Mesh {
public:
    using Vertexes = BufferData<Vertex>;
    using Indexes = BufferData<GLuint>;

public:
    explicit Mesh(const aiMesh* mesh);
    const Vertexes& getVertexes() const;
    const Indexes& getIndexes() const;

private:
    struct Impl;
    std::shared_ptr<Impl> impl;
};

} // namespace onux
