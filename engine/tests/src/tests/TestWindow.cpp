#include "tests/TestWindow.hpp"

#include <GL/glew.h> // Required before other OpenGL headers
#include <GLFW/glfw3.h>

TestWindow::TestWindow()
    : m_window(glfwCreateWindow(1280, 720, "Test", nullptr, nullptr)) {}

TestWindow::~TestWindow() {
    glfwDestroyWindow(m_window);
}

TestWindow::operator GLFWwindow*() {
    return m_window;
}
