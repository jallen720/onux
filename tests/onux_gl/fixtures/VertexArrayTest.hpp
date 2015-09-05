#pragma once

#include <GL/glew.h>

#include "OnuxTest.hpp"
#include "Scene.hpp"
#include "onux_gl/VertexBuffer.hpp"
#include "onux_gl/IndexBuffer.hpp"
#include "test_util.hpp"

using onux_gl::VertexBuffer;
using onux_gl::IndexBuffer;

class VertexArrayTest : public OnuxTest {
  const Scene scene { testModelPath("cube.obj") };
  const vector<Mesh> meshes = scene.getMeshes();
  const vector<Vertex> vertexes = meshes[0].getVertexes();
  const vector<GLuint> indexes = meshes[0].getIndexes();

public:
  const VertexBuffer validVertexBuffer {
    sizeof(Vertex) * vertexes.size(),
    &vertexes[0],
    GL_STATIC_DRAW
  };

  const IndexBuffer validIndexBuffer {
    sizeof(GLuint) * indexes.size(),
    &indexes[0],
    GL_STATIC_DRAW
  };
};
