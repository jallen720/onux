#include "gl/Texture.hpp"

#include <GL/glew.h> // Required before other OpenGL headers

#include "tests/fixtures/gl/TextureTest.hpp"
#include "tests/utils/expectNoThrow.hpp"
#include "exceptions/argErrors/NullArg.hpp"
#include "exceptions/argErrors/InvalidArg.hpp"
#include "exceptions/argErrors/InvalidMapKey.hpp"
#include "exceptions/argErrors/InvalidMapValue.hpp"
#include "gl/utils/getInt.hpp"

using onux::Texture;
using onux::getInt;
using onux::NullArg;
using onux::InvalidArg;
using onux::InvalidMapKey;
using onux::InvalidMapValue;

TEST_F(TextureTest, validCreation) {
    expectNoThrow([&] {
        Texture { validImage.get() };
    });
}

TEST_F(TextureTest, invalidImage) {
    EXPECT_THROW(Texture(nullptr), NullArg);
}

TEST_F(TextureTest, invalidOptionKey) {
    const GLint INVALID_KEY = 0;

    EXPECT_THROW(
        Texture(validImage.get(), {
            { INVALID_KEY, GL_LINEAR },
        }),
        InvalidMapKey
    );
}

TEST_F(TextureTest, invalidOptionValue) {
    const GLint INVALID_VALUE = 0;

    EXPECT_THROW(
        Texture(validImage.get(), {
            { GL_TEXTURE_MAG_FILTER, INVALID_VALUE },
        }),
        InvalidMapValue
    );
}

TEST_F(TextureTest, invalidOptionValueForKey) {
    // GL_LINEAR_MIPMAP_LINEAR is only valid for GL_TEXTURE_MIN_FILTER.
    EXPECT_THROW(
        Texture(validImage.get(), {
            { GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR },
        }),
        InvalidMapValue
    );
}

TEST_F(TextureTest, bind) {
    // A valid Texture will be bound to GL_TEXTURE_2D after creation.
    ASSERT_EQ(getInt(GL_TEXTURE_BINDING_2D), validTexture.getID());

    glBindTexture(GL_TEXTURE_2D, 0);
    ASSERT_NE(getInt(GL_TEXTURE_BINDING_2D), validTexture.getID());

    validTexture.bind(0);
    ASSERT_EQ(getInt(GL_TEXTURE_BINDING_2D), validTexture.getID());
}

TEST_F(TextureTest, bindToInvalidUnit) {
    static const GLuint INVALID_UNIT = getInt(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS);
    EXPECT_THROW(validTexture.bind(INVALID_UNIT), InvalidArg);
}
