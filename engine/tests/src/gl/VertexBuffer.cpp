#include "gl/VertexBuffer.hpp"

#include "tests/fixtures/gl/VertexBufferTest.hpp"
#include "exceptions/argErrors/InvalidArg.hpp"

using onux::InvalidArg;
using onux::VertexBuffer;
using onux::Vertex;

TEST_F(VertexBufferTest, invalidUsage) {
    static const GLenum INVALID_USAGE = 0;

    EXPECT_THROW(
        VertexBuffer(
            Vertex::LAYOUT,
            validVertexes,
            INVALID_USAGE
        ),
        InvalidArg
    );
}
