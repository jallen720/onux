#include "gl/VertexBuffer.hpp"

#include <stdexcept>

#include "fixtures/VertexBufferTest.hpp"

using std::runtime_error;
using onux::VertexBuffer;
using onux::Vertex;

TEST_F(VertexBufferTest, invalidUsage) {
  const GLenum INVALID_USAGE = 0;

  EXPECT_THROW(
    const VertexBuffer vertexBuffer(
      Vertex::LAYOUT,
      validData,
      INVALID_USAGE
    ),

    runtime_error
  );
}
