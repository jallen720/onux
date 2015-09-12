#include "gl/IndexBuffer.hpp"

#include "fixtures/IndexBufferTest.hpp"
#include "test_util.hpp"

using onux::IndexBuffer;

TEST_F(IndexBufferTest, invalidUsage) {
  expectGLError(GL_INVALID_ENUM, [&] {
    const GLenum INVALID_USAGE = 0;
    const IndexBuffer IndexBuffer(validData, INVALID_USAGE);
    IndexBuffer.loadData();
  });
}
