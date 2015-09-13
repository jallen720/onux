#include "gl/VertexBuffer.hpp"

#include "fixtures/VertexBufferTest.hpp"
#include "test_util.hpp"

using onux::VertexBuffer;

TEST_F(VertexBufferTest, invalidUsage) {
  expectGLError(GL_INVALID_ENUM, [&] {
    const GLenum INVALID_USAGE = 0;
    const VertexBuffer vertexBuffer(validData, INVALID_USAGE);
    vertexBuffer.loadData();
  });
}
