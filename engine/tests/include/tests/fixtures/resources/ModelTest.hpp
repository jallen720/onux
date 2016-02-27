#pragma once

#include <gtest/gtest.h>

#include "resources/ModelScene.hpp"
#include "tests/utils/validResourcePath.hpp"

struct ModelTest : testing::Test {
protected:
    const onux::ModelScene::Ptr cubeScene =
        onux::ModelScene::create(validResourcePath("modelScenes", "cube.obj"));
};
