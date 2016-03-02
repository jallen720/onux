#include "graphics/VertexData.hpp"

#include <functional>
#include <assimp/mesh.h>
#include <glm/glm.hpp>

#include "graphics/Vertex.hpp"
#include "graphics/VertexLayout.hpp"
#include "gl/interfaces/IBufferData.hpp"
#include "gl/interfaces/IVertexLayout.hpp"
#include "exceptions/validators/validateNotNull.hpp"
#include "exceptions/subsystemErrors/AssimpError.hpp"
#include "utils/toString.hpp"

using std::function;
using glm::vec2;
using glm::vec3;

namespace onux {

struct VertexData::Impl {
    const Vertexes      vertexes;
    const Indexes       indexes;
    const VertexLayout& layout;

    explicit Impl(const aiMesh* mesh);
};

static const Vertex createVertex(
    const aiVector3D& position,
    const aiVector3D& normal,
    const aiVector3D& uv
) {
    return Vertex {
        vec3(position.x, position.y, position.z),
        vec3(normal  .x, normal  .y, normal  .z),
        vec2(uv      .x, uv      .y)
    };
}

static const aiVector3D& getUV(
    const aiMesh*      mesh,
    const unsigned int vertexIndex,
    const unsigned int uvIndex
) {
    static const aiVector3D DEFAULT_UV(0, 0, 0);

    return mesh->HasTextureCoords(uvIndex)
           ? mesh->mTextureCoords[uvIndex][vertexIndex]
           : DEFAULT_UV;
}

static VertexData::Vertexes loadVertexes(const aiMesh* mesh) {
    VertexData::Vertexes vertexes;

    for (auto i = 0u; i < mesh->mNumVertices; i++) {
        vertexes.add(createVertex(
            mesh->mVertices[i],
            mesh->mNormals[i],
            getUV(mesh, i, 0)
        ));
    }

    return vertexes;
}

static const auto REQUIRED_FACE_INDEX_COUNT = 3u;

static const aiFace& getValidFace(const aiMesh* mesh, const unsigned int index) {
    const aiFace& face = mesh->mFaces[index];

    if (face.mNumIndices != REQUIRED_FACE_INDEX_COUNT) {
        throw AssimpError(
            "face [" + toString(index) + "] in mesh \"" + mesh->mName.data + "\" has " +
            toString(face.mNumIndices) + " indexes but " +
            toString(REQUIRED_FACE_INDEX_COUNT) + " indexes are required"
        );
    }

    return face;
}

static void forEachFace(const aiMesh* mesh, const function<void(const aiFace&)>& faceCB) {
    for (auto i = 0u; i < mesh->mNumFaces; i++) {
        faceCB(getValidFace(mesh, i));
    }
}

static VertexData::Indexes loadIndexes(const aiMesh* mesh) {
    VertexData::Indexes indexes;

    forEachFace(mesh, [&](const aiFace& face) {
        for (auto i = 0u; i < REQUIRED_FACE_INDEX_COUNT; i++) {
            indexes.add(face.mIndices[i]);
        }
    });

    return indexes;
}

static const aiMesh* getValidMesh(const aiMesh* mesh) {
    validateNotNull("mesh", "VertexData::VertexData", mesh);
    return mesh;
}

VertexData::VertexData(const aiMesh* mesh)
    : impl(new Impl(getValidMesh(mesh))) {}

VertexData::~VertexData() {}

const IBufferData& VertexData::getVertexes() const {
    return impl->vertexes;
}

const IBufferData& VertexData::getIndexes() const {
    return impl->indexes;
}

const IVertexLayout& VertexData::getLayout() const {
    return impl->layout;
}

// Implementation

VertexData::Impl::Impl(const aiMesh* mesh)
    : vertexes(loadVertexes(mesh))
    , indexes(loadIndexes(mesh))
    , layout(Vertex::LAYOUT) {}

} // namespace onux
