#include "sample/RenderingEngine.hpp"

#include <GL/glew.h>

#include "sample/Renderable.hpp"
#include "Camera.hpp"

static void drawElements() {
  static const GLenum  MODE  = GL_TRIANGLES;
  static const GLsizei COUNT = 32;
  static const GLenum  TYPE  = GL_UNSIGNED_INT;
  static const GLvoid* FIRST = 0;
  glDrawElements(MODE, COUNT, TYPE, FIRST);
}

void RenderingEngine::renderDrawables() {
  for (auto drawable : drawables) {
    drawable->enable(camera);
    drawElements();
  }
}

RenderingEngine::RenderingEngine(
  const Drawables& drawables,
  Camera& camera
) : drawables(drawables)
  , camera(camera) {}

static void clearBuffers() {
  static const GLbitfield MASKS =
    GL_COLOR_BUFFER_BIT |
    GL_DEPTH_BUFFER_BIT;

  glClear(MASKS);
}

void RenderingEngine::render() {
  clearBuffers();
  renderDrawables();
}
