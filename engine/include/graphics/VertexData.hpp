#pragma once

#include <memory>
#include <GL/glew.h>

#include "gl/interfaces/IVertexData.hpp"
#include "graphics/BufferData.hpp"

struct aiMesh;

namespace onux {

struct Vertex;

class VertexData : public IVertexData {
public:
    using Vertexes = BufferData<Vertex>;
    using Indexes  = BufferData<GLuint>;

public:
    explicit VertexData(const aiMesh* mesh);
    ~VertexData();

    // IVertexData
    virtual const IBufferData& getVertexes() const override;
    virtual const IBufferData& getIndexes() const override;
    virtual const IVertexLayout& getLayout() const override;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
