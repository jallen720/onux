#include "assets/utils/loadModels.hpp"

#include <string>

#include "assets/Model.hpp"
#include "resources/ModelScene.hpp"
#include "resources/utils/MeshData.hpp"
#include "gl/Texture.hpp"
#include "gl/ShaderProgram.hpp"
#include "graphics/VertexData.hpp"
#include "utils/pathRelativeTo.hpp"

using std::string;

namespace onux {

static Mesh::Textures getMeshTextures(
    const MeshData::TexturePaths& texturePaths,
    const UniqueMap<Texture>&     textures
) {
    static const auto IMAGES_DIRECTORY = "images/";

    Mesh::Textures meshTextures;

    for (const string& texturePath : texturePaths) {
        meshTextures.push_back(textures[pathRelativeTo(IMAGES_DIRECTORY, texturePath)]);
    }

    return meshTextures;
}

static Model::Meshes getMeshes(
    const ModelScene*         modelScene,
    const UniqueMap<Texture>& textures,
    const ShaderProgram*      shaderProgram
) {
    Model::Meshes meshes;

    modelScene->forEachMeshData([&](const MeshData& meshData) {
        meshes.push_back(Mesh::create(
            VertexData(meshData.getMesh()),
            getMeshTextures(meshData.getTexturePaths(), textures),
            shaderProgram
        ));
    });

    return meshes;
}

UniqueMap<Model> loadModels(
    const UniqueMap<ModelScene>&    modelScenes,
    const UniqueMap<ShaderProgram>& shaderPrograms,
    const UniqueMap<Texture>&       textures
) {
    UniqueMap<Model> models;

    modelScenes.forEach([&](const ModelScene* modelScene, const string& path) {
        models.add(
            path,
            Model::create(getMeshes(
                modelScene,
                textures,
                shaderPrograms["diffuse.yaml"]
            ))
        );
    });

    return models;
}

} // namespace onux
