#pragma once

#include <GLFW/glfw3.h>

namespace onux {

class Window {
public:
  Window(const int width, const int height, const char* name);
  ~Window();
  void makeContextCurrent() const;
  const float getAspect() const;
  const bool shouldClose() const;
  void swapBuffers() const;

private:
  GLFWwindow* m_glfwWindow;
  int         m_width;
  int         m_height;
};

} // namespace onux
