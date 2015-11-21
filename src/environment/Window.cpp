#include "environment/Window.hpp"

#include <cstring>
#include <string>
#include <GLFW/glfw3.h>

#include "environment/Input.hpp"
#include "exceptions/argErrors/InvalidArg.hpp"
#include "exceptions/argErrors/EmptyStringArg.hpp"
#include "exceptions/argErrors/NullArg.hpp"

using std::string;
using std::to_string;

namespace onux {

struct Window::Impl {
  GLFWwindow*  glfwWindow;
  Input        input;
  unsigned int width;
  unsigned int height;

  Impl(
    const unsigned int width,
    const unsigned int height,
    const char*        name
  );
};

Window::Window(
  const unsigned int width,
  const unsigned int height,
  const char*        name
) : impl(new Impl(width, height, name)) {}

Window::~Window() {
  glfwDestroyWindow(impl->glfwWindow);
}

void Window::makeContextCurrent() const {
  glfwMakeContextCurrent(impl->glfwWindow);
}

const float Window::getAspect() const {
  return (float)impl->width / impl->height;
}

const bool Window::shouldClose() const {
  return glfwWindowShouldClose(impl->glfwWindow);
}

void Window::swapBuffers() const {
  glfwSwapBuffers(impl->glfwWindow);
}

Input& Window::getInput() {
  return impl->input;
}

// Implementation

static void validateDimension(const unsigned int dimension, const string& dimensionName) {
  static const auto MIN_DIMENSION_SIZE = 1u;

  if (dimension < MIN_DIMENSION_SIZE) {
    throw InvalidArg(
      dimensionName,
      "Window",
      to_string(dimension),
      ">= " + to_string(MIN_DIMENSION_SIZE)
    );
  }
}

static bool isEmpty(const char* name) {
  return strcmp(name, "") == 0;
}

static void validateName(const char* name) {
  if (name == nullptr) {
    throw NullArg("name", "Window");
  }
  else if (isEmpty(name)) {
    throw EmptyStringArg("name", "Window");
  }
}

static GLFWwindow* getValidWindow(
  const unsigned int width,
  const unsigned int height,
  const char*        name
) {
  validateDimension(width, "width");
  validateDimension(height, "height");
  validateName(name);
  return glfwCreateWindow(width, height, name, nullptr, nullptr);
}

Window::Impl::Impl(
  const unsigned int width,
  const unsigned int height,
  const char*        name
) : glfwWindow(getValidWindow(width, height, name))
  , input(glfwWindow)
  , width(width)
  , height(height) {}

} // namespace onux
