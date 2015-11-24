#include "utils/expectGlError.hpp"

#include <gtest/gtest.h>

using std::function;

void expectGlError(const GLenum error, const function<void()>& block) {
  // Assert no error has already been generated before testing block error generation.
  ASSERT_EQ(GL_NO_ERROR, glGetError());

  // Run block where error is expected to be generated.
  block();

  // Expect error was generated during block.
  EXPECT_EQ(error, glGetError());
}
