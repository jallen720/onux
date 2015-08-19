#include "onux_gl/Vertex.hpp"

#include <vector>
#include <GL/glew.h>

using std::vector;
using namespace onux_gl;

class Attribute {
  const GLint     size;
  const GLenum    type;
  const GLboolean normalized;
  const GLvoid*   offset;

public:
  Attribute(
    const GLint     size,
    const GLenum    type,
    const GLboolean normalized,
    const GLvoid*   offset
  ) : size(size)
    , type(type)
    , normalized(normalized)
    , offset(offset) {}

  void definePointer(const GLuint index) const {
    static const GLsizei STRIDE = sizeof(Vertex);
    glEnableVertexAttribArray(index);
    glVertexAttribPointer(index, size, type, normalized, STRIDE, offset);
  }
};

Vertex::Vertex(const vec3 position, const vec4 color, const vec2 texCoord)
  : position(position)
  , color(color)
  , texCoord(texCoord) {}

void Vertex::attributePointers() {
  static const vector<Attribute> attributes {
    { 3, GL_FLOAT, GL_FALSE, (GLvoid*)offsetof(Vertex, position) },
    { 4, GL_FLOAT, GL_TRUE , (GLvoid*)offsetof(Vertex, color)    },
    { 2, GL_FLOAT, GL_TRUE , (GLvoid*)offsetof(Vertex, texCoord) },
  };

  for (GLuint i = 0; i < attributes.size(); i++)
    attributes[i].definePointer(i);
}
