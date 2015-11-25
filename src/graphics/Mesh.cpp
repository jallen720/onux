#include "graphics/Mesh.hpp"

#include <glm/glm.hpp>
#include <assimp/mesh.h>

#include "exceptions/argErrors/NullArg.hpp"

using glm::vec2;
using glm::vec3;

namespace onux {

struct Mesh::Impl {
    const Vertexes vertexes;
    const Indexes  indexes;

    Impl(const aiMesh* mesh);
};

static void validateMesh(const aiMesh* mesh) {
    if (mesh == nullptr) {
        throw NullArg("mesh", "Mesh");
    }
}

static const aiMesh* getValidMesh(const aiMesh* mesh) {
    validateMesh(mesh);
    return mesh;
}

Mesh::Mesh(const aiMesh* mesh)
    : impl(new Impl(getValidMesh(mesh))) {}

const Mesh::Vertexes& Mesh::getVertexes() const {
    return impl->vertexes;
}

const Mesh::Indexes& Mesh::getIndexes() const {
    return impl->indexes;
}

// Implementation

static const Vertex createVertex(
    const aiVector3D& position,
    const aiVector3D& normal,
    const aiVector3D& uv
) {
    return Vertex {
        vec3(position.x, position.y, position.z),
        vec3(normal.x  , normal.y  , normal.z  ),
        vec2(uv.x      , uv.y)
    };
}

static const aiVector3D& getUV(
    const aiMesh*      mesh,
    const unsigned int vertexIndex,
    const unsigned int uvIndex
) {
    static const aiVector3D VEC3_ZERO(0, 0, 0);

    return mesh->HasTextureCoords(uvIndex)
           ? mesh->mTextureCoords[uvIndex][vertexIndex]
           : VEC3_ZERO;
}

static const Mesh::Vertexes loadVertexes(const aiMesh* mesh) {
    Mesh::Vertexes vertexes;

    for (auto i = 0u; i < mesh->mNumVertices; i++) {
        vertexes.add(
            createVertex(
                mesh->mVertices[i],
                mesh->mNormals[i],
                getUV(mesh, i, 0)
            )
        );
    }

    return vertexes;
}

static const Mesh::Indexes loadIndexes(const aiMesh* mesh) {
    Mesh::Indexes indexes;

    for (auto i = 0u; i < mesh->mNumFaces; i++) {
        const aiFace& face = mesh->mFaces[i];
        indexes.add(face.mIndices[0]);
        indexes.add(face.mIndices[1]);
        indexes.add(face.mIndices[2]);
    }

    return indexes;
}

Mesh::Impl::Impl(const aiMesh* mesh)
    : vertexes(loadVertexes(mesh))
    , indexes(loadIndexes(mesh)) {}

} // namespace onux
