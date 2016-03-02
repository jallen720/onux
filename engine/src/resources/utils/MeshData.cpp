#include "resources/utils/MeshData.hpp"

#include <functional>
#include <assimp/scene.h>

#include "exceptions/validators/validateNotNull.hpp"
#include "exceptions/subsystemErrors/AssimpError.hpp"
#include "utils/toString.hpp"

#include "MACROS/ONUX_MOVE_ONLY_IMPLS.hpp"

using std::string;
using std::function;

namespace onux {

struct MeshData::Impl {
    const aiMesh*      mesh;
    const TexturePaths texturePaths;

    Impl(const aiMesh* mesh, const aiScene* scene);
};

static const aiMesh* getValidMesh(const aiMesh* mesh) {
    validateNotNull("mesh", "MeshData::MeshData", mesh);
    return mesh;
}

static const aiScene* getValidScene(const aiScene* scene) {
    validateNotNull("scene", "MeshData::MeshData", scene);
    return scene;
}

MeshData::MeshData(const aiMesh* mesh, const aiScene* scene)
    : impl(new Impl(
        getValidMesh(mesh),
        getValidScene(scene)
    )) {}

ONUX_MOVE_ONLY_IMPLS(MeshData)

const aiMesh* MeshData::getMesh() const {
    return impl->mesh;
}

auto MeshData::getTexturePaths() const -> const TexturePaths& {
    return impl->texturePaths;
}

// Implementation

static const string getMaterialName(const aiMaterial* material) {
    aiString materialName;
    material->Get(AI_MATKEY_NAME, materialName);
    return materialName.data;
}

static const aiTextureType TEXTURE_TYPE = aiTextureType_DIFFUSE;

static const string getTexturePath(const aiMaterial* material, const unsigned int index) {
    aiString texturePath;

    if (material->GetTexture(TEXTURE_TYPE, index, &texturePath) != AI_SUCCESS) {
        throw AssimpError(
            "failed get texture [" + toString(index) + "] from material "
            "\"" + getMaterialName(material) + "\""
        );
    }

    return texturePath.data;
}

using TexturePathCB = const function<void(const string&)>&;

static void forEachTexturePath(const aiMaterial* material, TexturePathCB texturePathCB) {
    unsigned int textureCount = material->GetTextureCount(TEXTURE_TYPE);

    for (auto i = 0u; i < textureCount; i++) {
        texturePathCB(getTexturePath(material, i));
    }
}

static const aiMaterial* getMaterial(const aiMesh* mesh, const aiScene* scene) {
    return scene->mMaterials[mesh->mMaterialIndex];
}

static MeshData::TexturePaths getValidTexturePaths(const aiMesh* mesh, const aiScene* scene) {
    MeshData::TexturePaths texturePaths;

    forEachTexturePath(getMaterial(mesh, scene), [&](const string& texturePath) {
        texturePaths.push_back(texturePath);
    });

    return texturePaths;
}

MeshData::Impl::Impl(const aiMesh* mesh, const aiScene* scene)
    : mesh(mesh)
    , texturePaths(getValidTexturePaths(this->mesh, scene)) {}

} // namespace onux
