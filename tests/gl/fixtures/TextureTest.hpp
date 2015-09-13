#pragma once

#include "OnuxTest.hpp"
#include "graphics/Image.hpp"
#include "test_util.hpp"

struct TextureTest : OnuxTest {
protected:
  const onux::Image validImage { testImagePath("valid.png") };
};
