#include "inputRegistryTest.hpp"

#include <GLFW/glfw3.h>

inputRegistryTest::inputRegistryTest()
  : window(glfwCreateWindow(1280, 720, "Test Window", nullptr, nullptr))
  , input(window) {}

inputRegistryTest::~inputRegistryTest() {
  glfwDestroyWindow(window);
}
