#pragma once

#include <gtest/gtest.h>

#include "graphics/utils/getValidAssimpScene.hpp"
#include "tests/utils/testModelPath.hpp"

struct MeshTest : testing::Test {
private:
    Assimp::Importer importer;

protected:
    const aiMesh* cubeMesh = onux::getValidAssimpScene(
        testModelPath("cube.obj"),
        importer
    )->mMeshes[0];
};
