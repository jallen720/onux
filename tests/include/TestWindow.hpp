#pragma once

#include "environment/Environment.hpp"

struct GLFWwindow;

class TestWindow {
public:
  TestWindow();
  ~TestWindow();
  operator GLFWwindow*();

private:
  const onux::Environment m_environment;
  GLFWwindow* m_window;
};
