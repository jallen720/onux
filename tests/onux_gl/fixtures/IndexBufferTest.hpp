#pragma once

#include <vector>

#include "OnuxTest.hpp"

using std::vector;

struct IndexBufferTest : OnuxTest {
  const vector<GLuint> validData { 0, 1, 2 };
};
