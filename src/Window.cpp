#include "Window.hpp"

Window::Window(const int width, const int height, const char* name)
  : m_glfwWindow(glfwCreateWindow(width, height, name, nullptr, nullptr))
  , m_width(width)
  , m_height(height) {
  makeContextCurrent();
}

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
