#include "Mesh.hpp"

#include <glm/glm.hpp>
#include <assimp/mesh.h>

using glm::vec2;
using glm::vec3;

static const Vertex newVertex(
  const aiVector3D& position,
  const aiVector3D& normal,
  const aiVector3D& uv
) {
  return Vertex(
    vec3(position.x, position.y, position.z),
    vec3(normal.x, normal.y, normal.z),
    vec2(uv.x, uv.y)
  );
}

static const aiVector3D getUV(
  const aiMesh* mesh,
  const unsigned int vertexIndex,
  const unsigned int uvIndex
) {
  static const aiVector3D VEC3_ZERO(0, 0, 0);
  return mesh->HasTextureCoords(uvIndex)
         ? mesh->mTextureCoords[uvIndex][vertexIndex]
         : VEC3_ZERO;
}

static const vector<Vertex> loadVertexes(const aiMesh* mesh) {
  vector<Vertex> vertexes;

  for (auto i = 0u; i < mesh->mNumVertices; i++) {
    vertexes.push_back(
      newVertex(
        mesh->mVertices[i],
        mesh->mNormals[i],
        getUV(mesh, i, 0)
      )
    );
  }

  return vertexes;
}

static const vector<GLuint> loadIndexes(const aiMesh* mesh) {
  vector<GLuint> indexes;

  for (auto i = 0u; i < mesh->mNumFaces; i++) {
    const aiFace& face = mesh->mFaces[i];
    indexes.push_back(face.mIndices[0]);
    indexes.push_back(face.mIndices[1]);
    indexes.push_back(face.mIndices[2]);
  }

  return indexes;
}

Mesh::Mesh(const aiMesh* mesh)
  : vertexes(loadVertexes(mesh))
  , indexes(loadIndexes(mesh))
  , vertexBuffer(vertexes)
  , indexBuffer(indexes)
  , vertexArray(vertexBuffer, indexBuffer) {}

const vector<Vertex>& Mesh::getVertexes() const {
  return vertexes;
}

const vector<GLuint>& Mesh::getIndexes() const {
  return indexes;
}

void Mesh::use() const {
  vertexArray.bind();
}
