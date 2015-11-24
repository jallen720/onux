#include "gl/utils/getInt.hpp"

#include "fixtures/getIntTest.hpp"
#include "testHelpers.hpp"

using onux::getInt;

TEST_F(getIntTest, validParameter) {
  ASSERT_EQ(GL_FALSE, getInt(GL_CULL_FACE));

  glEnable(GL_CULL_FACE);
  ASSERT_EQ(GL_TRUE, getInt(GL_CULL_FACE));
}

TEST_F(getIntTest, invalidParameter) {
  expectGLError(GL_INVALID_ENUM, [] {
    getInt(-1);
  });
}
