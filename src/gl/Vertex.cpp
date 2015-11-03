#include "gl/Vertex.hpp"

#include <vector>
#include <GL/glew.h>

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

void Vertex::definePointers() {
  typedef struct {
    const GLint     size;
    const GLenum    type;
    const GLboolean normalized;
    const GLvoid*   offset;

    void definePointer(const GLuint index) const {
      static const GLsizei STRIDE = sizeof(Vertex);
      glEnableVertexAttribArray(index);

      glVertexAttribPointer(
        index,
        size,
        type,
        normalized,
        STRIDE,
        offset
      );
    }
  } Attribute;

  static const vector<Attribute> ATTRIBUTES {
    { 3, GL_FLOAT, GL_FALSE, (GLvoid*)offsetof(Vertex, m_position) },
    { 3, GL_FLOAT, GL_FALSE, (GLvoid*)offsetof(Vertex, m_normal)   },
    { 2, GL_FLOAT, GL_TRUE , (GLvoid*)offsetof(Vertex, m_uv)       },
  };

  for (GLuint i = 0; i < ATTRIBUTES.size(); i++) {
    ATTRIBUTES[i].definePointer(i);
  }
}

} // namespace onux
