#include "graphics/Vertex.hpp"

#include "gl/interfaces/IVertexAttribute.hpp"


namespace onux {

// VertexAttribute definition

class VertexAttribute : public IVertexAttribute {
public:
  VertexAttribute(
    const GLint     elementCount,
    const GLenum    type,
    const GLboolean isNormalized,
    const GLvoid*   offset,
    const GLsizei   size
  );
  const GLint getElementCount() const;
  const GLenum getType() const;
  const GLboolean getIsNormalized() const;
  const GLvoid* getOffset() const;
  const GLsizei getSize() const;

private:
  const GLint     m_elementCount;
  const GLenum    m_type;
  const GLboolean m_isNormalized;
  const GLvoid*   m_offset;
  const GLsizei   m_size;
};

// Vertex implementation

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

// VertexAttribute implementation

VertexAttribute::VertexAttribute(
  const GLint     elementCount,
  const GLenum    type,
  const GLboolean isNormalized,
  const GLvoid*   offset,
  const GLsizei   size
) : m_elementCount(elementCount)
  , m_type(type)
  , m_isNormalized(isNormalized)
  , m_offset(offset)
  , m_size(size) {}

const GLint VertexAttribute::getElementCount() const {
  return m_elementCount;
}

const GLenum VertexAttribute::getType() const {
  return m_type;
}

const GLboolean VertexAttribute::getIsNormalized() const {
  return m_isNormalized;
}

const GLvoid* VertexAttribute::getOffset() const {
  return m_offset;
}

const GLsizei VertexAttribute::getSize() const {
  return m_size;
}

} // namespace onux
