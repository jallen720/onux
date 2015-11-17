#include "gl/helpers.hpp"

#include "fixtures/glHelpersTest.hpp"
#include "testHelpers.hpp"

using std::out_of_range;
using onux::getErrorMsg;
using onux::getInt;

TEST_F(glHelpersTest, validErrorMessage) {
  ASSERT_EQ("No error"                      , getErrorMsg(GL_NO_ERROR));
  ASSERT_EQ("Invalid enum"                  , getErrorMsg(GL_INVALID_ENUM));
  ASSERT_EQ("Invalid value"                 , getErrorMsg(GL_INVALID_VALUE));
  ASSERT_EQ("Invalid operation"             , getErrorMsg(GL_INVALID_OPERATION));
  ASSERT_EQ("Invalid framebuffer operation" , getErrorMsg(GL_INVALID_FRAMEBUFFER_OPERATION));
  ASSERT_EQ("Out of memory"                 , getErrorMsg(GL_OUT_OF_MEMORY));
  ASSERT_EQ("Stack underflow"               , getErrorMsg(GL_STACK_UNDERFLOW));
  ASSERT_EQ("Stack overflow"                , getErrorMsg(GL_STACK_OVERFLOW));
}

TEST_F(glHelpersTest, invalidErrorMessage) {
  EXPECT_THROW(
    getErrorMsg(-1),
    out_of_range
  );
}

TEST_F(glHelpersTest, getValidInt) {
  ASSERT_EQ(GL_FALSE, getInt(GL_CULL_FACE));

  glEnable(GL_CULL_FACE);
  ASSERT_EQ(GL_TRUE, getInt(GL_CULL_FACE));
}

TEST_F(glHelpersTest, getInvalidInt) {
  expectGLError(GL_INVALID_ENUM, [] {
    getInt(-1);
  });
}
