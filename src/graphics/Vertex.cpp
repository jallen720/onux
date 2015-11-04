#include "graphics/Vertex.hpp"

#include "graphics/VertexAttribute.hpp"

using glm::vec2;
using glm::vec3;

#define VERTEX_ATTRIBUTE(NAME, ELEMENT_COUNT, TYPE, IS_NORMALIZED) \
  const VertexAttribute<glm::vec ## ELEMENT_COUNT> NAME { \
    ELEMENT_COUNT, \
    GL_ ## TYPE, \
    GL_ ## IS_NORMALIZED, \
    (GLvoid*)offsetof(Vertex, NAME) \
  }

namespace onux {

static const struct {
  VERTEX_ATTRIBUTE(POSITION, 3, FLOAT, FALSE);
  VERTEX_ATTRIBUTE(NORMAL  , 3, FLOAT, FALSE);
  VERTEX_ATTRIBUTE(UV      , 2, FLOAT, TRUE );
} ATTRIBUTES;

const VertexLayout Vertex::LAYOUT({
  &ATTRIBUTES.POSITION,
  &ATTRIBUTES.NORMAL,
  &ATTRIBUTES.UV,
});

} // namespace onux
