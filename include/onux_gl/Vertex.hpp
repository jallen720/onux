#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

namespace onux_gl {

class Vertex {
public:
  Vertex();
  Vertex(
    const glm::vec3 position,
    const glm::vec3 normal,
    const glm::vec2 uv
  );
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
    const GLint     m_size;
    const GLenum    m_type;
    const GLboolean m_normalized;
    const GLvoid*   m_offset;
  }; // class Attribute

  const glm::vec3 m_position;
  const glm::vec3 m_normal;
  const glm::vec2 m_uv;
};

} // namespace onux_gl
