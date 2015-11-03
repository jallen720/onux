#include "gl/IndexBuffer.hpp"

#include "fixtures/IndexBufferTest.hpp"
#include "testHelpers.hpp"

using onux::IndexBuffer;

TEST_F(IndexBufferTest, invalidUsage) {
  expectGLError(GL_INVALID_ENUM, [&] {
    const GLenum INVALID_USAGE = 0;
    const IndexBuffer indexBuffer(validData, INVALID_USAGE);
    indexBuffer.loadData();
  });
}
