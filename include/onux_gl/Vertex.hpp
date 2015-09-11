#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

namespace onux_gl {

class Vertex {
public:
  Vertex();
  Vertex(const glm::vec3 position, const glm::vec3 normal, const glm::vec2 uv);
  static void attributePointers();

private:
  class Attribute {
  public:
    Attribute(
      const GLint     size,
      const GLenum    type,
      const GLboolean normalized,
      const GLvoid*   offset
    );
    void definePointer(const GLuint index) const;

  private:
    const GLint     size;
    const GLenum    type;
    const GLboolean normalized;
    const GLvoid*   offset;
  };

  const glm::vec3 position;
  const glm::vec3 normal;
  const glm::vec2 uv;
};

} // namespace onux_gl
