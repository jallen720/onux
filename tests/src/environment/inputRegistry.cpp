#include "environment/inputRegistry.hpp"

#include <stdexcept>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "fixtures/inputRegistryTest.hpp"
#include "test_util.hpp"

using std::runtime_error;
using onux::registerInput;

TEST_F(inputRegistryTest, validRegistry) {
  expectNoThrow([&] {
    registerInput(&input, window);
  });
}

TEST_F(inputRegistryTest, nullInput) {
  EXPECT_THROW(
    registerInput(nullptr, window),
    runtime_error
  );
}

TEST_F(inputRegistryTest, nullWindow) {
  EXPECT_THROW(
    registerInput(&input, nullptr),
    runtime_error
  );
}
