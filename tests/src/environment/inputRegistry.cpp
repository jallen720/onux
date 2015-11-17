#include "environment/inputRegistry.hpp"

#include <GL/glew.h> // Required before other OpenGL headers
#include <GLFW/glfw3.h>

#include "fixtures/inputRegistryTest.hpp"
#include "testHelpers.hpp"
#include "exceptions/Error.hpp"

using onux::registerInput;
using onux::Error;

TEST_F(inputRegistryTest, validRegistry) {
  expectNoThrow([&] {
    registerInput(&input, window);
  });
}

TEST_F(inputRegistryTest, nullInput) {
  EXPECT_THROW(
    registerInput(nullptr, window),
    Error
  );
}

TEST_F(inputRegistryTest, nullWindow) {
  EXPECT_THROW(
    registerInput(&input, nullptr),
    Error
  );
}
