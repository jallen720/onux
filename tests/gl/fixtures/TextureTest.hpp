#pragma once

#include "OnuxTest.hpp"
#include "Image.hpp"
#include "test_util.hpp"

struct TextureTest : OnuxTest {
protected:
  const Image validImage { testImagePath("valid.png") };
};
