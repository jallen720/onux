#include "gl/Texture.hpp"

#include <GL/glew.h> // Required before other OpenGL headers

#include "fixtures/TextureTest.hpp"
#include "gl/helpers.hpp"

using onux::Texture;
using onux::getInt;

TEST_F(TextureTest, validCreation) {
  expectNoThrow([&] {
    const Texture texture(&validImage);
  });
}

TEST_F(TextureTest, invalidOptions) {
  expectGLError(GL_INVALID_ENUM, [&] {
    const GLint INVALID_OPTION = 0;

    const Texture texture(&validImage, {
      { GL_TEXTURE_MIN_FILTER, GL_LINEAR      },
      { GL_TEXTURE_MAG_FILTER, INVALID_OPTION },
    });
  });
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
