#include <GL/glew.h> // Required before other OpenGL headers

#include "environment/Window.hpp"
#include "exceptions/InvalidArg.hpp"
#include "exceptions/EmptyStringArg.hpp"
#include "exceptions/NullArg.hpp"
#include "fixtures/WindowTest.hpp"
#include "testHelpers.hpp"

using onux::Window;
using onux::InvalidArg;
using onux::EmptyStringArg;
using onux::NullArg;

TEST_F(WindowTest, validCreation) {
  expectNoThrow([] {
    const Window window(1280, 720, "Test Window");
  });
}

TEST_F(WindowTest, invalidName) {
  EXPECT_THROW(
    const Window window(1280, 720, nullptr),
    NullArg
  );

  EXPECT_THROW(
    const Window window(1280, 720, ""),
    EmptyStringArg
  );
}

TEST_F(WindowTest, invalidDimensions) {
  EXPECT_THROW(
    const Window window(1280, 0, "Test Window"),
    InvalidArg
  );

  EXPECT_THROW(
    const Window window(0, 720, "Test Window"),
    InvalidArg
  );

  EXPECT_THROW(
    const Window window(0, 0, "Test Window"),
    InvalidArg
  );
}

TEST_F(WindowTest, aspect) {
  const Window window(1280, 720, "Test Window");

  EXPECT_EQ(
    (float)1280 / 720,
    window.getAspect()
  );
}
