#pragma once

#include <gtest/gtest.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "test_util.hpp"

using testing::Test;
using Assimp::Importer;

class MeshTest : public Test {
  Importer importer;

public:
  const aiMesh* cubeMesh = importer.ReadFile(
    testModelPath("cube.obj"),
    aiProcess_GenSmoothNormals      |
    aiProcess_CalcTangentSpace      |
    aiProcess_Triangulate           |
    aiProcess_JoinIdenticalVertices |
    aiProcess_SortByPType
  )->mMeshes[0];
};
