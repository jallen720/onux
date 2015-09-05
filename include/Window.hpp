#pragma once

#include <GLFW/glfw3.h>

class Window {
  GLFWwindow* glfwWindow;
  int width;
  int height;

public:
  Window(const int width, const int height, const char* name);
  ~Window();
  void makeContextCurrent() const;
  const float getAspect() const;
  const bool shouldClose() const;
  void swapBuffers() const;
};
