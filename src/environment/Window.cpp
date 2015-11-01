#include "environment/Window.hpp"

#include <GLFW/glfw3.h>

namespace onux {

Window::Window(
  const unsigned int width,
  const unsigned int height,
  const char*        name
) : m_glfwWindow(glfwCreateWindow(width, height, name, nullptr, nullptr))
  , m_input(m_glfwWindow)
  , m_width(width)
  , m_height(height) {}

Window::~Window() {
  glfwDestroyWindow(m_glfwWindow);
}

void Window::makeContextCurrent() const {
  glfwMakeContextCurrent(m_glfwWindow);
}

const float Window::getAspect() const {
  return (float)m_width / m_height;
}

const bool Window::shouldClose() const {
  return glfwWindowShouldClose(m_glfwWindow);
}

void Window::swapBuffers() const {
  glfwSwapBuffers(m_glfwWindow);
}

Input& Window::getInput() {
  return m_input;
}

} // namespace onux
