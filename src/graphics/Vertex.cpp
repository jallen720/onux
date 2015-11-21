#include "graphics/Vertex.hpp"

#include "gl/interfaces/IVertexAttribute.hpp"

#define VERTEX_ATTRIBUTE(NAME, ELEMENT_COUNT, TYPE, IS_NORMALIZED) \
  const VertexAttribute<glm::vec ## ELEMENT_COUNT> NAME { \
    ELEMENT_COUNT, \
    GL_ ## TYPE, \
    GL_ ## IS_NORMALIZED, \
    (GLvoid*)offsetof(Vertex, NAME) \
  }

namespace onux {

template<typename T>
class VertexAttribute : public IVertexAttribute {
private:
  const GLint     m_elementCount;
  const GLenum    m_type;
  const GLboolean m_isNormalized;
  const GLvoid*   m_offset;

public:
  VertexAttribute(
    const GLint     elementCount,
    const GLenum    type,
    const GLboolean isNormalized,
    const GLvoid*   offset
  ) : m_elementCount(elementCount)
    , m_type(type)
    , m_isNormalized(isNormalized)
    , m_offset(offset) {}

  const GLint getElementCount() const {
    return m_elementCount;
  }

  const GLenum getType() const {
    return m_type;
  }

  const GLboolean getIsNormalized() const {
    return m_isNormalized;
  }

  const GLvoid* getOffset() const {
    return m_offset;
  }

  const GLsizei getSize() const {
    return sizeof(T);
  }
};

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
