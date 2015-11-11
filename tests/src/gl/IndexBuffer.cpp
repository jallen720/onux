#include "gl/IndexBuffer.hpp"

#include <stdexcept>

#include "fixtures/IndexBufferTest.hpp"

using std::runtime_error;
using onux::IndexBuffer;

TEST_F(IndexBufferTest, invalidUsage) {
  const GLenum INVALID_USAGE = 0;

  EXPECT_THROW(
    const IndexBuffer indexBuffer(validData, INVALID_USAGE),
    runtime_error
  );
}
