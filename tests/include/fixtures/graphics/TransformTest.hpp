#pragma once

#include <gtest/gtest.h>

#include "graphics/Transform.hpp"

struct TransformTest : testing::Test {
protected:
  onux::Transform transform;
};
