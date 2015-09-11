#pragma once

#include <vector>
#include <GL/glew.h>

#include "onux_gl/Vertex.hpp"
#include "onux_gl/VertexBuffer.hpp"
#include "onux_gl/IndexBuffer.hpp"
#include "onux_gl/VertexArray.hpp"

struct aiMesh;

class Mesh {
public:
  typedef std::vector<onux_gl::Vertex> Vertexes;
  typedef std::vector<GLuint>          Indexes;

  Mesh(const aiMesh* mesh);
  const Vertexes& getVertexes() const;
  const Indexes& getIndexes() const;
  void use() const;

private:
  const Vertexes vertexes;
  const Indexes  indexes;
  const onux_gl::VertexBuffer vertexBuffer;
  const onux_gl::IndexBuffer  indexBuffer;
  const onux_gl::VertexArray  vertexArray;
};
