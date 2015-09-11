#pragma once

#include <vector>
#include <GL/glew.h>

#include "onux_gl/Vertex.hpp"

struct aiMesh;

class Mesh {
public:
  typedef std::vector<onux_gl::Vertex> Vertexes;
  typedef std::vector<GLuint> Indexes;

  Mesh(const aiMesh* mesh);
  const Vertexes& getVertexes() const;
  const Indexes& getIndexes() const;

private:
  const Vertexes vertexes;
  const Indexes indexes;
};
