#pragma once

#include <memory>
#include <GL/glew.h>

#include "graphics/Vertex.hpp"
#include "graphics/BufferData.hpp"

struct aiMesh;

namespace onux {

class Mesh {
public:
    typedef BufferData<Vertex> Vertexes;
    typedef BufferData<GLuint> Indexes;

public:
    explicit Mesh(const aiMesh* mesh);
    const Vertexes& getVertexes() const;
    const Indexes& getIndexes() const;

private:
    struct Impl;
    std::shared_ptr<Impl> impl;
};

} // namespace onux
