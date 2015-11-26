#include "graphics/VertexAttribute.hpp"

#include <vector>
#include <string>

#include "utils/contains.hpp"
#include "utils/transform.hpp"
#include "utils/toString.hpp"
#include "gl/utils/ValidValues.hpp"
#include "exceptions/argErrors/InvalidArg.hpp"

using std::vector;
using std::string;

namespace onux {

struct VertexAttribute::Impl {
    const GLint     elementCount;
    const GLenum    type;
    const GLboolean isNormalized;
    const GLvoid*   offset;
    const GLsizei   size;
};

static void validateElementCount(const GLint elementCount) {
    static const vector<GLint> VALID_ELEMENT_COUNTS { 1, 2, 3, 4 };

    if (!contains(VALID_ELEMENT_COUNTS, elementCount)) {
        throw InvalidArg(
            "elementCount",
            "VertexAttribute::VertexAttribute",
            transform<string>(VALID_ELEMENT_COUNTS, toString<GLint>)
        );
    }
}

static const GLint getValidElementCount(const GLint elementCount) {
    validateElementCount(elementCount);
    return elementCount;
}

static void validateType(const GLenum type) {
    static const ValidValues VALID_TYPES({
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
    });

    if (!VALID_TYPES.contains(type)) {
        throw InvalidArg(
            "type",
            "VertexAttribute::VertexAttribute",
            VALID_TYPES.getNames()
        );
    }
}

static const GLenum getValidType(const GLenum type) {
    validateType(type);
    return type;
}

static void validateIsNormalized(const GLboolean isNormalized) {
    static const ValidValues VALID_IS_NORMALIZED_VALUES({
        VALID_VALUE(GL_TRUE),
        VALID_VALUE(GL_FALSE),
    });

    if (!VALID_IS_NORMALIZED_VALUES.contains(isNormalized)) {
        throw InvalidArg(
            "isNormalized",
            "VertexAttribute::VertexAttribute",
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
)   : impl(new Impl({
        getValidElementCount(elementCount),
        getValidType(type),
        getValidIsNormalized(isNormalized),
        offset,
        size
    })) {}

VertexAttribute::~VertexAttribute() {}

const GLint VertexAttribute::getElementCount() const {
    return impl->elementCount;
}

const GLenum VertexAttribute::getType() const {
    return impl->type;
}

const GLboolean VertexAttribute::getIsNormalized() const {
    return impl->isNormalized;
}

const GLvoid* VertexAttribute::getOffset() const {
    return impl->offset;
}

const GLsizei VertexAttribute::getSize() const {
    return impl->size;
}

} // namespace onux

