#include "gl/VertexArray.hpp"

#include "tests/fixtures/gl/VertexArrayTest.hpp"
#include "tests/utils/expectNoThrow.hpp"
#include "gl/utils/getInt.hpp"

using onux::VertexArray;
using onux::getInt;

TEST_F(VertexArrayTest, validCreation) {
    expectNoThrow([&] {
        VertexArray { validVertexData };
    });
}

TEST_F(VertexArrayTest, bind) {
    const VertexArray vertexArray(validVertexData);

    // A VertexArray will be bound after successful creation.
    ASSERT_EQ(getInt(GL_VERTEX_ARRAY_BINDING), vertexArray.getID());

    glBindVertexArray(0);
    ASSERT_NE(getInt(GL_VERTEX_ARRAY_BINDING), vertexArray.getID());

    vertexArray.bind();
    ASSERT_EQ(getInt(GL_VERTEX_ARRAY_BINDING), vertexArray.getID());
}
