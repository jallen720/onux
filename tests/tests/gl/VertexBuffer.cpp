#include "gl/VertexBuffer.hpp"

#include "exceptions/argErrors/InvalidArg.hpp"
#include "fixtures/gl/VertexBufferTest.hpp"

using onux::InvalidArg;
using onux::VertexBuffer;
using onux::Vertex;

TEST_F(VertexBufferTest, invalidUsage) {
    static const GLenum INVALID_USAGE = 0;

    EXPECT_THROW(
        VertexBuffer(
            Vertex::LAYOUT,
            validData,
            INVALID_USAGE
        ),
        InvalidArg
    );
}
