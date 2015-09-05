#include "Window.hpp"

Window::Window(const int width, const int height, const char* name)
  : glfwWindow(glfwCreateWindow(width, height, name, nullptr, nullptr))
  , width(width)
  , height(height) {
  makeContextCurrent();
}

Window::~Window() {
  glfwDestroyWindow(glfwWindow);
}

void Window::makeContextCurrent() const {
  glfwMakeContextCurrent(glfwWindow);
}

const float Window::getAspect() const {
  return (float)width / height;
}

const bool Window::shouldClose() const {
  return glfwWindowShouldClose(glfwWindow);
}

void Window::swapBuffers() const {
  glfwSwapBuffers(glfwWindow);
}
