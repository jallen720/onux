#pragma once

#include <GL/glew.h>

namespace onux {

class VertexAttribute {
public:
  VertexAttribute(
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
};

} // namespace onux
