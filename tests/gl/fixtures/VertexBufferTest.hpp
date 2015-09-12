#pragma once

#include <vector>

#include "OnuxTest.hpp"
#include "gl/Vertex.hpp"

struct VertexBufferTest : OnuxTest {
protected:
  const std::vector<onux::Vertex> validData {
    onux::Vertex(),
    onux::Vertex(),
    onux::Vertex(),
  };
};
