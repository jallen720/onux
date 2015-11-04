#include "engine/GraphicsEngine.hpp"

#include <GL/glew.h>

#include "engine/Renderable.hpp"
#include "graphics/Camera.hpp"

namespace onux {

GraphicsEngine::GraphicsEngine(Drawables& drawables, Camera& camera)
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
  renderDrawables();
}

void GraphicsEngine::renderDrawables() const {
  for (auto drawable : m_drawables) {
    drawable->enable(m_camera);
    drawable->getMeshRenderer().render();
  }
}

} // namespace onux
