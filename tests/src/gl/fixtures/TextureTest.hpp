#pragma once

#include "OnuxTest.hpp"
#include "graphics/Image.hpp"
#include "testHelpers.hpp"

struct TextureTest : OnuxTest {
protected:
  const onux::Image validImage { testImagePath("valid.png") };
};
