#include "sample/Engine.hpp"

#include <stdexcept>
#include <thread>
#include <chrono>
#include <GL/glew.h>

#include "Window.hpp"
#include "Camera.hpp"
#include "sample/RenderingEngine.hpp"
#include "onux_gl/helpers.hpp"

using std::runtime_error;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;
using onux_gl::getErrorMsg;

void Engine::renderObjects() {
  renderingEngine.clearBuffers();
  renderingEngine.render(camera);
  window.swapBuffers();
}

static void validateNoGLError(const GLenum error) {
  if (error != GL_NO_ERROR)
    throw runtime_error(
      "Unhandled OpenGL error generated:\n"
      "  " + getErrorMsg(error) + "\n\n"
    );
}

void Engine::processFrame() {
  glfwPollEvents();
  renderObjects();
  validateNoGLError(glGetError());
}

Engine::Engine(
  const Window& window,
  Camera& camera,
  RenderingEngine& renderingEngine
) : window(window)
  , camera(camera)
  , renderingEngine(renderingEngine) {
  validateNoGLError(glGetError());
}

static void frameWait(float frameStart) {
  static const float FPS = 60.f;
  long wait = ((1.f / FPS) * 1000) - (glfwGetTime() - frameStart);
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
