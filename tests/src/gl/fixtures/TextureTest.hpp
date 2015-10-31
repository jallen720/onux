#pragma once

#include "OnuxTest.hpp"
#include "graphics/Image.hpp"
#include "testUtil.hpp"

struct TextureTest : OnuxTest {
protected:
  const onux::Image validImage { testImagePath("valid.png") };
};
