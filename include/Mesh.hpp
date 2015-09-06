#pragma once

#include <vector>
#include <GL/glew.h>

#include "onux_gl/Vertex.hpp"
#include "onux_gl/VertexBuffer.hpp"
#include "onux_gl/IndexBuffer.hpp"
#include "onux_gl/VertexArray.hpp"

using std::vector;
using onux_gl::Vertex;
using onux_gl::VertexBuffer;
using onux_gl::IndexBuffer;
using onux_gl::VertexArray;

struct aiMesh;

class Mesh {
  const vector<Vertex> vertexes;
  const vector<GLuint> indexes;
  const VertexBuffer   vertexBuffer;
  const IndexBuffer    indexBuffer;
  const VertexArray    vertexArray;

public:
  Mesh(const aiMesh* mesh);
  const vector<Vertex>& getVertexes() const;
  const vector<GLuint>& getIndexes() const;
  void use() const;
};
