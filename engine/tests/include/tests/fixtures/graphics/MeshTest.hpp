#pragma once

#include <gtest/gtest.h>

#include "resources/ModelScene.hpp"
#include "tests/utils/validResourcePath.hpp"

struct MeshTest : testing::Test {
private:
    const onux::ModelScene::Ptr cubeScene =
        onux::ModelScene::create(validResourcePath("modelScenes", "cube.obj"));

protected:
    const aiMesh* cubeAssimpMesh = cubeScene->getMesh(0);
};
