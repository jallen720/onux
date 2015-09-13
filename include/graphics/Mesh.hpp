#pragma once

#include <vector>
#include <GL/glew.h>

#include "gl/Vertex.hpp"

struct aiMesh;

namespace onux {

class Mesh {
public:
  typedef std::vector<Vertex> Vertexes;
  typedef std::vector<GLuint> Indexes;

  Mesh(const aiMesh* mesh);
  const Vertexes& getVertexes() const;
  const Indexes& getIndexes() const;

private:
  const Vertexes m_vertexes;
  const Indexes  m_indexes;
};

} // namespace onux
