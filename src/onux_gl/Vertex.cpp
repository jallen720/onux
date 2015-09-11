#include "onux_gl/Vertex.hpp"

#include <vector>

using std::vector;
using glm::vec2;
using glm::vec3;

namespace onux_gl {

Vertex::Vertex() {}

Vertex::Vertex(const vec3 position, const vec3 normal, const vec2 uv)
  : position(position)
  , normal(normal)
  , uv(uv) {}

void Vertex::attributePointers() {
  static const vector<Attribute> attributes {
    { 3, GL_FLOAT, GL_FALSE, (GLvoid*)offsetof(Vertex, position) },
    { 3, GL_FLOAT, GL_FALSE, (GLvoid*)offsetof(Vertex, normal)   },
    { 2, GL_FLOAT, GL_TRUE , (GLvoid*)offsetof(Vertex, uv)       },
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
) : size(size)
  , type(type)
  , normalized(normalized)
  , offset(offset) {}

void Vertex::Attribute::definePointer(const GLuint index) const {
  static const GLsizei STRIDE = sizeof(Vertex);
  glEnableVertexAttribArray(index);
  glVertexAttribPointer(index, size, type, normalized, STRIDE, offset);
}

} // namespace onux_gl
