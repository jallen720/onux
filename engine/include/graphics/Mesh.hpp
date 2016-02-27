#pragma once

#include <memory>
#include <GL/glew.h>

#include "graphics/Vertex.hpp"
#include "graphics/BufferData.hpp"

struct aiMesh;

namespace onux {

class Mesh {
public:
    using Ptr      = std::unique_ptr<const Mesh>;
    using Vertexes = BufferData<Vertex>;
    using Indexes  = BufferData<GLuint>;

public:
    static Ptr create(const aiMesh* assimpMesh);

public:
    ~Mesh();
    const Vertexes& getVertexes() const;
    const Indexes& getIndexes() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;

    explicit Mesh(const aiMesh* assimpMesh);
};

} // namespace onux
