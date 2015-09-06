#include "sample/GraphicsEngine.hpp"

#include <GL/glew.h>

#include "sample/Renderable.hpp"
#include "Camera.hpp"

static void drawElements(const GLsizei indexCount) {
  static const GLenum  MODE  = GL_TRIANGLES;
  static const GLenum  TYPE  = GL_UNSIGNED_INT;
  static const GLvoid* FIRST = 0;
  glDrawElements(MODE, indexCount, TYPE, FIRST);
}

GraphicsEngine::GraphicsEngine(const Drawables& drawables, Camera& camera)
  : drawables(drawables)
  , camera(camera) {}

void GraphicsEngine::clearBuffers() const {
  static const GLbitfield MASKS =
    GL_COLOR_BUFFER_BIT |
    GL_DEPTH_BUFFER_BIT;

  glClear(MASKS);
}

void GraphicsEngine::render() {
  for (auto drawable : drawables) {
    drawable->enable(camera);
    drawElements(drawable->getMesh()->getIndexes().size());
  }
}
