#pragma once

#include <vector>
#include <GL/glew.h>

#include "onux_gl/Vertex.hpp"

using std::vector;
using onux_gl::Vertex;

struct aiMesh;

class Mesh {
  const vector<Vertex> vertexes;
  const vector<GLuint> indexes;

public:
  Mesh(const aiMesh* mesh);
  const vector<Vertex>& getVertexes() const;
  const vector<GLuint>& getIndexes() const;
};
