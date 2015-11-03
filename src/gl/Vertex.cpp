#include "gl/Vertex.hpp"

#include <vector>

using std::vector;
using glm::vec2;
using glm::vec3;

namespace onux {

Vertex::Vertex() {}

Vertex::Vertex(
  const vec3 position,
  const vec3 normal,
  const vec2 uv
) : m_position(position)
  , m_normal(normal)
  , m_uv(uv) {}

void Vertex::attributePointers() {
  static const vector<Attribute> attributes {
    { 3, GL_FLOAT, GL_FALSE, (GLvoid*)offsetof(Vertex, m_position) },
    { 3, GL_FLOAT, GL_FALSE, (GLvoid*)offsetof(Vertex, m_normal)   },
    { 2, GL_FLOAT, GL_TRUE , (GLvoid*)offsetof(Vertex, m_uv)       },
  };

  for (GLuint i = 0; i < attributes.size(); i++) {
    attributes[i].definePointer(i);
  }
}

Vertex::Attribute::Attribute(
  const GLint     size,
  const GLenum    type,
  const GLboolean normalized,
  const GLvoid*   offset
) : m_size(size)
  , m_type(type)
  , m_normalized(normalized)
  , m_offset(offset) {}

void Vertex::Attribute::definePointer(const GLuint index) const {
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
