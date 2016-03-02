#pragma once

#include "tests/fixtures/gl/OnuxTest.hpp"
#include "graphics/VertexData.hpp"
#include "graphics/Vertex.hpp"

struct VertexBufferTest : OnuxTest {
protected:
    const onux::VertexData::Vertexes validVertexes {
        onux::Vertex(),
        onux::Vertex(),
        onux::Vertex(),
    };
};
