#pragma once

#include <gtest/gtest.h>

#include "graphics/ViewTransform.hpp"

struct ViewTransformTest : testing::Test {
protected:
  onux::ViewTransform viewTransform;
};
