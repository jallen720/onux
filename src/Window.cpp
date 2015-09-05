#include "Window.hpp"

Window::Window(const int width, const int height, const char* name)
  : window(glfwCreateWindow(width, height, name, nullptr, nullptr))
  , width(width)
  , height(height) {
  makeContextCurrent();
}

Window::~Window() {
  glfwDestroyWindow(window);
}

void Window::makeContextCurrent() const {
  glfwMakeContextCurrent(window);
}

const float Window::getAspect() const {
  return (float)width / height;
}

const bool Window::shouldClose() const {
  return glfwWindowShouldClose(window);
}

void Window::swapBuffers() const {
  glfwSwapBuffers(window);
}
