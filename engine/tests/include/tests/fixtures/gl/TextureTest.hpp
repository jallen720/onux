#pragma once

#include "tests/fixtures/gl/OnuxTest.hpp"
#include "graphics/Image.hpp"
#include "tests/utils/testImagePath.hpp"

struct TextureTest : OnuxTest {
protected:
    const onux::Image validImage { testImagePath("valid.png") };
    const onux::Texture validTexture { &validImage };
};
