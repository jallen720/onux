#include "environment/Window.hpp"

#include <cstring>
#include <string>
#include <stdexcept>
#include <GLFW/glfw3.h>

#include "environment/Input.hpp"

using std::string;
using std::runtime_error;

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

static bool isValidDimension(const unsigned int dimension) {
  static const auto MIN_DIMENSION_SIZE = 1u;
  return dimension >= MIN_DIMENSION_SIZE;
}

static void validateDimesion(const unsigned int dimension, const string name) {
  if (!isValidDimension(dimension)) {
    throw runtime_error("Window " + name + " must be greater than 0!");
  }
}

static bool isValidName(const char* name) {
  return name != nullptr &&
         strcmp(name, "") != 0;
}

static void validateName(const char* name) {
  if (!isValidName(name)) {
    throw runtime_error("Invalid name parameter passed to Window!");
  }
}

static GLFWwindow* loadWindow(
  const unsigned int width,
  const unsigned int height,
  const char*        name
) {
  validateDimesion(width, "width");
  validateDimesion(height, "height");
  validateName(name);
  return glfwCreateWindow(width, height, name, nullptr, nullptr);
}

Window::Impl::Impl(
  const unsigned int width,
  const unsigned int height,
  const char*        name
) : glfwWindow(loadWindow(width, height, name))
  , input(glfwWindow)
  , width(width)
  , height(height) {}

} // namespace onux
