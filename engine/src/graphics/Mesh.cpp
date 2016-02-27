#include "graphics/Mesh.hpp"

#include <glm/glm.hpp>
#include <assimp/mesh.h>

#include "exceptions/validators/validateNotNull.hpp"

using glm::vec2;
using glm::vec3;

namespace onux {

struct Mesh::Impl {
    const Vertexes vertexes;
    const Indexes  indexes;

    explicit Impl(const aiMesh* assimpMesh);
};

auto Mesh::create(const aiMesh* assimpMesh) -> Ptr {
    validateNotNull("assimpMesh", "Mesh::create", assimpMesh);
    return Ptr(new Mesh(assimpMesh));
}

Mesh::Mesh(const aiMesh* assimpMesh)
    : impl(new Impl(assimpMesh)) {}

Mesh::~Mesh() {}

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
    const aiMesh*      assimpMesh,
    const unsigned int vertexIndex,
    const unsigned int uvIndex
) {
    static const aiVector3D DEFAULT_UV(0, 0, 0);

    return assimpMesh->HasTextureCoords(uvIndex)
           ? assimpMesh->mTextureCoords[uvIndex][vertexIndex]
           : DEFAULT_UV;
}

static Mesh::Vertexes loadVertexes(const aiMesh* assimpMesh) {
    Mesh::Vertexes vertexes;

    for (auto i = 0u; i < assimpMesh->mNumVertices; i++) {
        vertexes.add(
            createVertex(
                assimpMesh->mVertices[i],
                assimpMesh->mNormals[i],
                getUV(assimpMesh, i, 0)
            )
        );
    }

    return vertexes;
}

static Mesh::Indexes loadIndexes(const aiMesh* assimpMesh) {
    Mesh::Indexes indexes;

    for (auto i = 0u; i < assimpMesh->mNumFaces; i++) {
        const aiFace& face = assimpMesh->mFaces[i];
        indexes.add(face.mIndices[0]);
        indexes.add(face.mIndices[1]);
        indexes.add(face.mIndices[2]);
    }

    return indexes;
}

Mesh::Impl::Impl(const aiMesh* assimpMesh)
    : vertexes(loadVertexes(assimpMesh))
    , indexes(loadIndexes(assimpMesh)) {}

} // namespace onux
