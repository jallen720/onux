#include "environment/Window.hpp"

#include <GLFW/glfw3.h>

#include "environment/Input.hpp"

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

Window::Impl::Impl(
  const unsigned int width,
  const unsigned int height,
  const char*        name
) : glfwWindow(glfwCreateWindow(width, height, name, nullptr, nullptr))
  , input(glfwWindow)
  , width(width)
  , height(height) {}

} // namespace onux
