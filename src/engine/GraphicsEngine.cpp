#include "engine/GraphicsEngine.hpp"

#include <GL/glew.h>

#include "engine/Renderable.hpp"
#include "graphics/Camera.hpp"

// Temp
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
using glm::vec3;
// Temp

namespace onux {

// Temp
static void modCam(Camera& camera) {
  float mod = sin(glfwGetTime());
  auto amt = 3u;
  camera.getViewTransform().setRotation(vec3(0.0f, mod * (45.0f / amt), 0.0f));
  camera.getViewTransform().setPosition(vec3(mod * amt, 0.0f, 0.0f));
}
// Temp

GraphicsEngine::GraphicsEngine(const Drawables& drawables, Camera& camera)
  : m_drawables(drawables)
  , m_camera(camera) {}

static void clearBuffers() {
  static const GLbitfield MASKS =
    GL_COLOR_BUFFER_BIT |
    GL_DEPTH_BUFFER_BIT;

  glClear(MASKS);
}

void GraphicsEngine::render() {
  clearBuffers();
  modCam(m_camera);
  renderDrawables();
}

void GraphicsEngine::renderDrawables() const {
  for (auto drawable : m_drawables) {
    drawable->enable(m_camera);
    drawable->getMeshRenderer().render();
  }
}

} // namespace onux
