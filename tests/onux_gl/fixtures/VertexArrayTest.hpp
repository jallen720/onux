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
  Scene::Meshes& meshes = scene.getMeshes();

public:
  const VertexBuffer validVertexBuffer { meshes[0]->getVertexes() };
  const IndexBuffer  validIndexBuffer  { meshes[0]->getIndexes()  };
};
