#pragma once

#include <vector>

#include "OnuxTest.hpp"
#include "onux_gl/Vertex.hpp"

using std::vector;
using onux_gl::Vertex;

struct VertexBufferTest : OnuxTest {
  const vector<Vertex> validData { Vertex() };
};
