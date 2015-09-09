// Must be included before other OpenGL headers.
#include <GL/glew.h>

#include "Window.hpp"

#include <stdexcept>

#include "fixtures/WindowTest.hpp"
#include "test_util.hpp"

using std::runtime_error;

TEST_F(WindowTest, validCreation) {
  expectNoThrow([] {
    const Window window(1280, 720, "Test Window");
  });
}

TEST_F(WindowTest, invalidDimensions) {
  EXPECT_THROW(
    const Window window(1280, 0, "Test Window"),
    runtime_error
  );

  EXPECT_THROW(
    const Window window(0, 720, "Test Window"),
    runtime_error
  );

  EXPECT_THROW(
    const Window window(0, 0, "Test Window"),
    runtime_error
  );
}

TEST_F(WindowTest, aspect) {
  const Window window(1280, 720, "Test Window");
  EXPECT_EQ((float)1280 / 720, window.getAspect());
}
