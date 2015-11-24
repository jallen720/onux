#include "gl/utils/getErrorMessage.hpp"

#include "fixtures/getErrorMessageTest.hpp"

using std::out_of_range;
using onux::getErrorMessage;

TEST_F(getErrorMessageTest, validErrorMessage) {
  ASSERT_EQ("No error"                      , getErrorMessage(GL_NO_ERROR));
  ASSERT_EQ("Invalid enum"                  , getErrorMessage(GL_INVALID_ENUM));
  ASSERT_EQ("Invalid value"                 , getErrorMessage(GL_INVALID_VALUE));
  ASSERT_EQ("Invalid operation"             , getErrorMessage(GL_INVALID_OPERATION));
  ASSERT_EQ("Invalid framebuffer operation" , getErrorMessage(GL_INVALID_FRAMEBUFFER_OPERATION));
  ASSERT_EQ("Out of memory"                 , getErrorMessage(GL_OUT_OF_MEMORY));
  ASSERT_EQ("Stack underflow"               , getErrorMessage(GL_STACK_UNDERFLOW));
  ASSERT_EQ("Stack overflow"                , getErrorMessage(GL_STACK_OVERFLOW));
}

TEST_F(getErrorMessageTest, invalidError) {
  EXPECT_THROW(
    getErrorMessage(-1),
    out_of_range
  );
}
