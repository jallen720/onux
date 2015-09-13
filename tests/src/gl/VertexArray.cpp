#include "gl/VertexArray.hpp"

#include "fixtures/VertexArrayTest.hpp"
#include "gl/helpers.hpp"
#include "test_util.hpp"

using onux::VertexArray;
using onux::getInt;

TEST_F(VertexArrayTest, validCreation) {
  expectNoThrow([&] {
    const VertexArray vertexArray(
      validVertexBuffer,
      validIndexBuffer
    );
  });
}

TEST_F(VertexArrayTest, bind) {
  const VertexArray vertexArray(
    validVertexBuffer,
    validIndexBuffer
  );

  // A VertexArray will be bound after successful creation.
  ASSERT_EQ(getInt(GL_VERTEX_ARRAY_BINDING), vertexArray.getID());

  glBindVertexArray(0);
  ASSERT_NE(getInt(GL_VERTEX_ARRAY_BINDING), vertexArray.getID());

  vertexArray.bind();
  ASSERT_EQ(getInt(GL_VERTEX_ARRAY_BINDING), vertexArray.getID());
}
