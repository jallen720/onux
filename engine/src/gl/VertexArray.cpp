#include "gl/VertexArray.hpp"

#include "gl/interfaces/IVertexData.hpp"
#include "gl/interfaces/IVertexLayout.hpp"
#include "gl/interfaces/IBufferData.hpp"
#include "gl/VertexBuffer.hpp"
#include "gl/IndexBuffer.hpp"

namespace onux {

struct VertexArray::Impl {
    const VertexBuffer vertexBuffer;
    const IndexBuffer  indexBuffer;
    const size_t       indexCount;

    explicit Impl(const IVertexData& vertexData);
};

// VertexArray represents 1 vertex array.
static const GLsizei VERTEX_ARRAY_COUNT = 1;

static GLuint createVertexArray() {
    GLuint id;
    glGenVertexArrays(VERTEX_ARRAY_COUNT, &id);
    return id;
}

VertexArray::VertexArray(const IVertexData& vertexData)
    : GLData(createVertexArray())
    , impl(new Impl(vertexData)) {
    bind();
    impl->vertexBuffer.loadData();
    impl->indexBuffer.loadData();
}

VertexArray::~VertexArray() {
    glDeleteVertexArrays(VERTEX_ARRAY_COUNT, &getID());
}

void VertexArray::bind() const {
    glBindVertexArray(getID());
}

const size_t VertexArray::getIndexCount() const {
    return impl->indexCount;
}

// Implementation

VertexArray::Impl::Impl(const IVertexData& vertexData)
    : vertexBuffer(vertexData.getLayout(), vertexData.getVertexes())
    , indexBuffer(vertexData.getIndexes())
    , indexCount(vertexData.getIndexes().getCount()) {}

} // namespace onux
