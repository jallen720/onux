#pragma once

#include <vector>
#include <GL/glew.h>

#include "gl/Vertex.hpp"
#include "graphics/BufferData.hpp"

struct aiMesh;

namespace onux {

class Mesh {
public:
  typedef BufferData<Vertex> Vertexes;
  typedef BufferData<GLuint> Indexes;

  Mesh(const aiMesh* mesh);
  const Vertexes& getVertexes() const;
  const Indexes& getIndexes() const;

private:
  const Vertexes m_vertexes;
  const Indexes  m_indexes;
};

} // namespace onux
