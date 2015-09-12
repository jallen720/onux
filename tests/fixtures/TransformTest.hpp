#pragma once

#include <gtest/gtest.h>

#include "Transform.hpp"

struct TransformTest : testing::Test {
protected:
  onux::Transform transform;
};
