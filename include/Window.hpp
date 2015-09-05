#pragma once

#include <GLFW/glfw3.h>

#include "GLFWEnvironment.hpp"

class Window : GLFWEnvironment {
  GLFWwindow* window;
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
