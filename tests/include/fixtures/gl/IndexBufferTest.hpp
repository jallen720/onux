#pragma once

#include "fixtures/gl/OnuxTest.hpp"
#include "graphics/Mesh.hpp"

struct IndexBufferTest : OnuxTest {
protected:
  const onux::Mesh::Indexes validData { 0, 1, 2 };
};
