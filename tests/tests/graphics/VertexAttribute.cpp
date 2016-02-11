#include "graphics/VertexAttribute.hpp"

#include <gtest/gtest.h>

#include "utils/expectNoThrow.hpp"
#include "exceptions/argErrors/InvalidArg.hpp"

using onux::VertexAttribute;
using onux::InvalidArg;

static const GLint     VALID_ELEMENT_COUNT = 1;
static const GLenum    VALID_TYPE          = GL_FLOAT;
static const GLboolean VALID_IS_NORMALIZED = GL_FALSE;
static const GLvoid*   VALID_OFFSET        = nullptr;
static const GLsizei   VALID_SIZE          = sizeof(GLint);

TEST(VertexAttributeTest, validCreation) {
    expectNoThrow([] {
        VertexAttribute {
            VALID_ELEMENT_COUNT,
            VALID_TYPE,
            VALID_IS_NORMALIZED,
            VALID_OFFSET,
            VALID_SIZE
        };
    });
}

TEST(VertexAttributeTest, invalidElementCount) {
    // Valid element counts are 1 - 4.
    static const GLint INVALID_ELEMENT_COUNTS[] { 0, 5 };

    for (const GLint invalidElementCount : INVALID_ELEMENT_COUNTS) {
        EXPECT_THROW(
            VertexAttribute(
                invalidElementCount,
                VALID_TYPE,
                VALID_IS_NORMALIZED,
                VALID_OFFSET,
                VALID_SIZE
            ),
            InvalidArg
        );
    }
}

TEST(VertexAttributeTest, invalidType) {
    static const GLenum INVALID_TYPE = 0;

    EXPECT_THROW(
        VertexAttribute(
            VALID_ELEMENT_COUNT,
            INVALID_TYPE,
            VALID_IS_NORMALIZED,
            VALID_OFFSET,
            VALID_SIZE
        ),
        InvalidArg
    );
}

TEST(VertexAttributeTest, invalidIsNormalized) {
    static const GLboolean INVALID_IS_NORMALIZED = -1;

    EXPECT_THROW(
        VertexAttribute(
            VALID_ELEMENT_COUNT,
            VALID_TYPE,
            INVALID_IS_NORMALIZED,
            VALID_OFFSET,
            VALID_SIZE
        ),
        InvalidArg
    );
}
