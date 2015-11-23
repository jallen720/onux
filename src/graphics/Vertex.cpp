#include "graphics/Vertex.hpp"

#include <vector>
#include <string>

#include "gl/interfaces/IVertexAttribute.hpp"
#include "utils/contains.hpp"
#include "utils/map.hpp"
#include "utils/toString.hpp"
#include "utils/ValidValues.hpp"
#include "exceptions/argErrors/InvalidArg.hpp"

using std::vector;
using std::string;

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

static void validateElementCount(const GLint elementCount) {
  static const vector<GLint> VALID_ELEMENT_COUNTS { 1, 2, 3, 4 };

  if (!contains(VALID_ELEMENT_COUNTS, elementCount)) {
    throw InvalidArg(
      "elementCount",
      "VertexAttribute",
      map<string>(VALID_ELEMENT_COUNTS, toString<GLint>)
    );
  }
}

static const GLint getValidElementCount(const GLint elementCount) {
  validateElementCount(elementCount);
  return elementCount;
}

static void validateType(const GLenum type) {
  static const ValidValues VALID_TYPES {
    VALID_VALUE(GL_BYTE),
    VALID_VALUE(GL_UNSIGNED_BYTE),
    VALID_VALUE(GL_SHORT),
    VALID_VALUE(GL_UNSIGNED_SHORT),
    VALID_VALUE(GL_INT),
    VALID_VALUE(GL_UNSIGNED_INT),
    VALID_VALUE(GL_HALF_FLOAT),
    VALID_VALUE(GL_FLOAT),
    VALID_VALUE(GL_DOUBLE),
    VALID_VALUE(GL_FIXED),
    VALID_VALUE(GL_INT_2_10_10_10_REV),
    VALID_VALUE(GL_UNSIGNED_INT_2_10_10_10_REV),
    VALID_VALUE(GL_UNSIGNED_INT_10F_11F_11F_REV),
  };

  if (!VALID_TYPES.contains(type)) {
    throw InvalidArg("type", "VertexAttribute", VALID_TYPES.getNames());
  }
}

static const GLenum getValidType(const GLenum type) {
  validateType(type);
  return type;
}

static void validateIsNormalized(const GLboolean isNormalized) {
  static const ValidValues VALID_IS_NORMALIZED_VALUES {
    VALID_VALUE(GL_TRUE),
    VALID_VALUE(GL_FALSE),
  };

  if (!VALID_IS_NORMALIZED_VALUES.contains(isNormalized)) {
    throw InvalidArg(
      "isNormalized",
      "VertexAttribute",
      VALID_IS_NORMALIZED_VALUES.getNames()
    );
  }
}

static const GLboolean getValidIsNormalized(const GLboolean isNormalized) {
  validateIsNormalized(isNormalized);
  return isNormalized;
}

VertexAttribute::VertexAttribute(
  const GLint     elementCount,
  const GLenum    type,
  const GLboolean isNormalized,
  const GLvoid*   offset,
  const GLsizei   size
) : m_elementCount(getValidElementCount(elementCount))
  , m_type(getValidType(type))
  , m_isNormalized(getValidIsNormalized(isNormalized))
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
