#pragma once

#include "tests/fixtures/gl/OnuxTest.hpp"
#include "graphics/Mesh.hpp"

struct VertexBufferTest : OnuxTest {
protected:
    const onux::Mesh::Vertexes validData {
        onux::Vertex(),
        onux::Vertex(),
        onux::Vertex(),
    };
};
