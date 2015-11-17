#include "gl/Texture.hpp"

#include <GL/glew.h> // Required before other OpenGL headers

#include "fixtures/TextureTest.hpp"
#include "gl/helpers.hpp"
#include "exceptions/NullArg.hpp"
#include "exceptions/InvalidMapKey.hpp"
#include "exceptions/InvalidMapValue.hpp"

using onux::Texture;
using onux::getInt;
using onux::NullArg;
using onux::InvalidMapKey;
using onux::InvalidMapValue;

TEST_F(TextureTest, validCreation) {
  expectNoThrow([&] {
    const Texture texture(&validImage);
  });
}

TEST_F(TextureTest, invalidImage) {
  EXPECT_THROW(
    const Texture texture(nullptr),
    NullArg
  );
}

TEST_F(TextureTest, invalidOptionKey) {
  const GLint INVALID_KEY = 0;

  EXPECT_THROW(
    const Texture texture(&validImage, {
      { INVALID_KEY, GL_LINEAR },
    }),

    InvalidMapKey
  );
}

TEST_F(TextureTest, invalidOptionValue) {
  const GLint INVALID_VALUE = 0;

  EXPECT_THROW(
    const Texture texture(&validImage, {
      { GL_TEXTURE_MAG_FILTER, INVALID_VALUE },
    }),

    InvalidMapValue
  );
}

TEST_F(TextureTest, invalidOptionValueForKey) {
  // GL_LINEAR_MIPMAP_LINEAR is only valid for GL_TEXTURE_MIN_FILTER.
  EXPECT_THROW(
    const Texture texture(&validImage, {
      { GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR },
    }),

    InvalidMapValue
  );
}

TEST_F(TextureTest, bind) {
  const Texture texture(&validImage);

  // A valid Texture will be bound to GL_TEXTURE_2D after creation.
  ASSERT_EQ(getInt(GL_TEXTURE_BINDING_2D), texture.getID());

  glBindTexture(GL_TEXTURE_2D, 0);
  ASSERT_NE(getInt(GL_TEXTURE_BINDING_2D), texture.getID());

  texture.bind(0);
  ASSERT_EQ(getInt(GL_TEXTURE_BINDING_2D), texture.getID());
}
