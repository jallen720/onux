#include "gl/IndexBuffer.hpp"

#include "exceptions/argErrors/InvalidArg.hpp"
#include "tests/fixtures/gl/IndexBufferTest.hpp"

using onux::InvalidArg;
using onux::IndexBuffer;

TEST_F(IndexBufferTest, invalidUsage) {
    static const GLenum INVALID_USAGE = 0;

    EXPECT_THROW(IndexBuffer(validData, INVALID_USAGE), InvalidArg);
}
