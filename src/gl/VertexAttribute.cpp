#include "gl/VertexAttribute.hpp"

#include "gl/Vertex.hpp"

namespace onux {

VertexAttribute::VertexAttribute(
  const GLint     size,
  const GLenum    type,
  const GLboolean normalized,
  const GLvoid*   offset
) : m_size(size)
  , m_type(type)
  , m_normalized(normalized)
  , m_offset(offset) {}

void VertexAttribute::definePointer(const GLuint index) const {
  static const GLsizei STRIDE = sizeof(Vertex);
  glEnableVertexAttribArray(index);

  glVertexAttribPointer(
    index,
    m_size,
    m_type,
    m_normalized,
    STRIDE,
    m_offset
  );
}

} // namespace onux
