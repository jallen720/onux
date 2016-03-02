#pragma once

#include "tests/fixtures/gl/OnuxTest.hpp"
#include "graphics/VertexData.hpp"

struct IndexBufferTest : OnuxTest {
protected:
    const onux::VertexData::Indexes validIndexes { 0, 1, 2 };
};
