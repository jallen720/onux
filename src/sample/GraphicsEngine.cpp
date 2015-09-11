#include "sample/GraphicsEngine.hpp"

#include <GL/glew.h>

#include "sample/Renderable.hpp"
#include "Camera.hpp"

GraphicsEngine::GraphicsEngine(const Drawables& drawables, Camera& camera)
  : drawables(drawables)
  , camera(camera) {}

static void clearBuffers() {
  static const GLbitfield MASKS =
    GL_COLOR_BUFFER_BIT |
    GL_DEPTH_BUFFER_BIT;

  glClear(MASKS);
}

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
using glm::vec3;
static void modCam(Camera& camera) {
  float mod = sin(glfwGetTime());
  auto amt = 3u;
  camera.getViewTransform().setRotation(vec3(0.0f, mod * (45.0f / amt), 0.0f));
  camera.getViewTransform().setPosition(vec3(mod * amt, 0.0f, 0.0f));
}

void GraphicsEngine::render() {
  clearBuffers();
  modCam(camera);
  renderDrawables();
}

void GraphicsEngine::renderDrawables() const {
  for (auto drawable : drawables) {
    drawable->enable(camera);
    drawable->getMeshRenderer().render();
  }
}
