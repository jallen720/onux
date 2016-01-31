#pragma once

#include <gtest/gtest.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "utils/testScenePath.hpp"

struct MeshTest : testing::Test {
private:
    const unsigned int POST_PROCESSING_FLAGS =
        aiProcess_GenSmoothNormals      |
        aiProcess_CalcTangentSpace      |
        aiProcess_Triangulate           |
        aiProcess_JoinIdenticalVertices |
        aiProcess_SortByPType;

    Assimp::Importer importer;

protected:
    const aiMesh* cubeMesh = importer.ReadFile(
        testScenePath("cube.obj"),
        POST_PROCESSING_FLAGS
    )->mMeshes[0];
};
