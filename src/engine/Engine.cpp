#include "engine/Engine.hpp"

#include <stdexcept>
#include <thread>
#include <chrono>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "environment/Window.hpp"
#include "engine/GraphicsEngine.hpp"
#include "gl/helpers.hpp"

using std::runtime_error;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

namespace onux {

static void validateNoGLError(const GLenum error) {
  if (error != GL_NO_ERROR) {
    throw runtime_error(
      "Unhandled OpenGL error generated:\n"
      "  " + getErrorMsg(error) + "\n"
    );
  }
}

Engine::Engine(const Window& window, GraphicsEngine& graphicsEngine)
  : m_window(window)
  , m_graphicsEngine(graphicsEngine) {
  validateNoGLError(glGetError());
}

static void frameWait(float frameStart) {
  static const float FPS = 60.0f;
  long wait = ((1.0f / FPS) * 1000) - (glfwGetTime() - frameStart);
  sleep_for(milliseconds(wait));
}

static void handleFrameTiming(float& frameStart) {
  frameWait(frameStart);
  frameStart = glfwGetTime();
}

void Engine::run() {
  float frameStart = glfwGetTime();

  while (!m_window.shouldClose()) {
    processFrame();
    handleFrameTiming(frameStart);
  }
}

void Engine::renderObjects() {
  m_graphicsEngine.render();
  m_window.swapBuffers();
}

void Engine::processFrame() {
  glfwPollEvents();
  renderObjects();
  validateNoGLError(glGetError());
}

} // namespace onux
