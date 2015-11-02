#pragma once

#include "environment/Input.hpp"

struct GLFWwindow;

namespace onux {

class Window {
public:
  Window(
    const unsigned int width,
    const unsigned int height,
    const char*        name
  );
  ~Window();
  void makeContextCurrent() const;
  const float getAspect() const;
  const bool shouldClose() const;
  void swapBuffers() const;
  Input& getInput();

private:
  GLFWwindow*  m_glfwWindow;
  Input        m_input;
  unsigned int m_width;
  unsigned int m_height;
};

} // namespace onux
