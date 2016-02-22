#pragma once

#include <gtest/gtest.h>

#include "graphics/utils/getValidAssimpScene.hpp"
#include "tests/utils/validResourcePath.hpp"

struct MeshTest : testing::Test {
private:
    Assimp::Importer importer;

protected:
    const aiMesh* cubeMesh = onux::getValidAssimpScene(
        validResourcePath("models", "cube.obj"),
        importer
    )->mMeshes[0];
};
