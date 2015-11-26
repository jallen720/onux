#include "graphics/Vertex.hpp"

#include "graphics/VertexAttribute.hpp"

namespace onux {

#define VERTEX_ATTRIBUTE(NAME, ELEMENT_COUNT, TYPE, IS_NORMALIZED) \
    const VertexAttribute NAME { \
        ELEMENT_COUNT, \
        GL_ ## TYPE, \
        GL_ ## IS_NORMALIZED, \
        (GLvoid*)offsetof(Vertex, NAME), \
        sizeof(glm::vec ## ELEMENT_COUNT) \
    }

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
