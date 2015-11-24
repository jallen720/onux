#include "engine/Engine.hpp"

#include <thread>
#include <chrono>
#include <GL/glew.h> // Required before other OpenGL headers
#include <GLFW/glfw3.h>

#include "environment/Window.hpp"
#include "engine/GraphicsEngine.hpp"
#include "gl/utils/validateNoGLError.hpp"

using std::this_thread::sleep_for;
using std::chrono::milliseconds;

namespace onux {

struct Engine::Impl {
  const Window&   window;
  GraphicsEngine& graphicsEngine;

  Impl(const Window& window, GraphicsEngine& graphicsEngine);
  void renderObjects();
  void processFrame();
};

Engine::Engine(const Window& window, GraphicsEngine& graphicsEngine)
  : impl(new Impl(window, graphicsEngine)) {
  validateNoGLError();
}

Engine::~Engine() {}

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

  while (!impl->window.shouldClose()) {
    impl->processFrame();
    handleFrameTiming(frameStart);
  }
}

// Implementation

Engine::Impl::Impl(const Window& window, GraphicsEngine& graphicsEngine)
  : window(window)
  , graphicsEngine(graphicsEngine) {}

void Engine::Impl::renderObjects() {
  graphicsEngine.render();
  window.swapBuffers();
}

void Engine::Impl::processFrame() {
  glfwPollEvents();
  renderObjects();
  validateNoGLError();
}

} // namespace onux
