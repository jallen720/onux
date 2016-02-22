#pragma once

#include "tests/fixtures/gl/OnuxTest.hpp"
#include "graphics/Image.hpp"
#include "tests/utils/validResourcePath.hpp"

struct TextureTest : OnuxTest {
protected:
    const onux::Image::Ptr validImage =
        onux::Image::create(validResourcePath("images", "valid.png"));

    const onux::Texture validTexture { validImage.get() };
};
