#include "gl/Vertex.hpp"

#include <vector>

#include "gl/VertexAttribute.hpp"

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
  static const vector<VertexAttribute> attributes {
    { 3, GL_FLOAT, GL_FALSE, (GLvoid*)offsetof(Vertex, m_position) },
    { 3, GL_FLOAT, GL_FALSE, (GLvoid*)offsetof(Vertex, m_normal)   },
    { 2, GL_FLOAT, GL_TRUE , (GLvoid*)offsetof(Vertex, m_uv)       },
  };

  for (GLuint i = 0; i < attributes.size(); i++) {
    attributes[i].definePointer(i);
  }
}

} // namespace onux
