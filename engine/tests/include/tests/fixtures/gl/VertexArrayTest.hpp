#pragma once

#include "tests/fixtures/gl/OnuxTest.hpp"
#include "resources/ResourceManager.hpp"
#include "graphics/VertexData.hpp"
#include "resources/utils/MeshData.hpp"
#include "resources/ModelScene.hpp"

struct VertexArrayTest : OnuxTest {
private:
    const onux::ResourceManager validResourceManager { "tests/resources/valid/" };

protected:
    const onux::VertexData validVertexData {
        validResourceManager
            .getModelScenes()["box.obj"]
            ->getMeshDatas()[0]
            .getMesh()
    };
};
