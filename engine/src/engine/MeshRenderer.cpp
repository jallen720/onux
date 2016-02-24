#include "engine/MeshRenderer.hpp"

#include "graphics/Mesh.hpp"
#include "graphics/Vertex.hpp"
#include "gl/VertexBuffer.hpp"
#include "gl/IndexBuffer.hpp"
#include "gl/VertexArray.hpp"

namespace onux {

struct MeshRenderer::Impl {
    const Mesh*        mesh;
    const VertexBuffer vertexBuffer;
    const IndexBuffer  indexBuffer;
    const VertexArray  vertexArray;

    explicit Impl(const Mesh* mesh);
};

MeshRenderer::MeshRenderer(const Mesh* mesh)
    : impl(new Impl(mesh)) {}

MeshRenderer::~MeshRenderer() {}

static void drawElements(const GLsizei indexCount) {
    static const GLenum  MODE  = GL_TRIANGLES;
    static const GLenum  TYPE  = GL_UNSIGNED_INT;
    static const GLvoid* FIRST = 0;
    glDrawElements(MODE, indexCount, TYPE, FIRST);
}

void MeshRenderer::render() const {
    impl->vertexArray.bind();
    drawElements(impl->mesh->getIndexes().getCount());
}

// Implementation

MeshRenderer::Impl::Impl(const Mesh* mesh)
    : mesh(mesh)
    , vertexBuffer(Vertex::LAYOUT, this->mesh->getVertexes())
    , indexBuffer(this->mesh->getIndexes())
    , vertexArray(vertexBuffer, this->indexBuffer) {}

} // namespace onux
