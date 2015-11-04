#include "gl/VertexBuffer.hpp"

#include "fixtures/VertexBufferTest.hpp"
#include "testHelpers.hpp"

using onux::VertexBuffer;
using onux::Vertex;

TEST_F(VertexBufferTest, invalidUsage) {
  expectGLError(GL_INVALID_ENUM, [&] {
    const GLenum INVALID_USAGE = 0;

    const VertexBuffer vertexBuffer(
      Vertex::LAYOUT,
      validData,
      INVALID_USAGE
    );

    vertexBuffer.loadData();
  });
}
