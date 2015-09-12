#pragma once

#include <vector>

#include "OnuxTest.hpp"
#include "onux_gl/Vertex.hpp"

struct VertexBufferTest : OnuxTest {
protected:
  const std::vector<onux_gl::Vertex> validData {
    onux_gl::Vertex(),
    onux_gl::Vertex(),
    onux_gl::Vertex(),
  };
};
