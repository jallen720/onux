#pragma once

#include <gtest/gtest.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "utils/testScenePath.hpp"

struct MeshTest : testing::Test {
private:
    Assimp::Importer importer;

protected:
    const aiMesh* cubeMesh = importer.ReadFile(
        testScenePath("cube.obj"),
        aiProcess_GenSmoothNormals      |
        aiProcess_CalcTangentSpace      |
        aiProcess_Triangulate           |
        aiProcess_JoinIdenticalVertices |
        aiProcess_SortByPType
    )->mMeshes[0];
};
