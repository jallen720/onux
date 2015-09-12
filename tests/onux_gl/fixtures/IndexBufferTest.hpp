#pragma once

#include <vector>

#include "OnuxTest.hpp"

struct IndexBufferTest : OnuxTest {
protected:
  const std::vector<GLuint> validData { 0, 1, 2 };
};
