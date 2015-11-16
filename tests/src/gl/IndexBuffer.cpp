#include "gl/IndexBuffer.hpp"

#include "exceptions/InvalidArg.hpp"
#include "fixtures/IndexBufferTest.hpp"

using onux::InvalidArg;
using onux::IndexBuffer;

TEST_F(IndexBufferTest, invalidUsage) {
  const GLenum INVALID_USAGE = 0;

  EXPECT_THROW(
    const IndexBuffer indexBuffer(validData, INVALID_USAGE),
    InvalidArg
  );
}
