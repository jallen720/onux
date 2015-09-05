#pragma once

#include "OnuxTest.hpp"
#include "Image.hpp"
#include "test_util.hpp"

struct TextureTest : OnuxTest {
  const Image validImage { testImagePath("valid.png") };
};
