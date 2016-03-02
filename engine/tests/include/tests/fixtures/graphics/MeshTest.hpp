#pragma once

#include "tests/fixtures/gl/OnuxTest.hpp"
#include "resources/ResourceManager.hpp"
#include "resources/ModelScene.hpp"
#include "resources/utils/MeshData.hpp"
#include "assets/AssetManager.hpp"
#include "graphics/Mesh.hpp"
#include "graphics/VertexData.hpp"

struct MeshTest : OnuxTest {
private:
    const onux::ResourceManager validResourceManager { "tests/resources/valid/" };
    const onux::AssetManager    validAssetManager { validResourceManager };

protected:
    const onux::VertexData validVertexData {
        validResourceManager
            .getModelScenes()["box.obj"]
            ->getMeshDatas()[0]
            .getMesh()
    };

    const onux::Mesh::Textures validTextures {
        validAssetManager.getTextures()["valid.png"]
    };

    const onux::ShaderProgram* validShaderProgram =
        validAssetManager.getShaderPrograms()["valid.yaml"];
};
