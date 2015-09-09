#include "sample/Engine.hpp"

#include <stdexcept>
#include <thread>
#include <chrono>
#include <GL/glew.h>

#include "Window.hpp"
#include "sample/GraphicsEngine.hpp"
#include "onux_gl/helpers.hpp"

using std::runtime_error;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;
using onux_gl::getErrorMsg;

void Engine::renderObjects() {
  graphicsEngine.clearBuffers();
  graphicsEngine.render();
  window.swapBuffers();
}

static void validateNoGLError(const GLenum error) {
  if (error != GL_NO_ERROR) {
    throw runtime_error(
      "Unhandled OpenGL error generated:\n"
      "  " + getErrorMsg(error) + "\n"
    );
  }
}

void Engine::processFrame() {
  glfwPollEvents();
  renderObjects();
  validateNoGLError(glGetError());
}

Engine::Engine(const Window& window, GraphicsEngine& graphicsEngine)
  : window(window)
  , graphicsEngine(graphicsEngine) {
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

  while (!window.shouldClose()) {
    processFrame();
    handleFrameTiming(frameStart);
  }
}
