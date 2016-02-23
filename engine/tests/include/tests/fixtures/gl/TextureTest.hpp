#pragma once

#include "tests/fixtures/gl/OnuxTest.hpp"
#include "tests/utils/validResourcePath.hpp"
#include "resources/Image.hpp"

struct TextureTest : OnuxTest {
protected:
    const onux::Image::Ptr validImage =
        onux::Image::create(validResourcePath("images", "valid.png"));

    const onux::Texture::Ptr validTexture =
        onux::Texture::create(validImage.get());
};
