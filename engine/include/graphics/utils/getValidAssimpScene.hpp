#pragma once

#include <string>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/Importer.hpp>

namespace onux {

static const unsigned int DEFAULT_IMPORT_FLAGS =
    aiProcess_GenSmoothNormals      |
    aiProcess_CalcTangentSpace      |
    aiProcess_Triangulate           |
    aiProcess_JoinIdenticalVertices |
    aiProcess_SortByPType;

const aiScene* getValidAssimpScene(
    const std::string& path,
    Assimp::Importer&  importer,
    const unsigned int importFlags = DEFAULT_IMPORT_FLAGS
);

} // namespace onux
