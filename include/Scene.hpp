#pragma once

#include <string>
#include <vector>
#include <assimp/Importer.hpp>

#include "Mesh.hpp"

using std::string;
using std::vector;
using Assimp::Importer;

struct aiScene;

class Scene {
  Importer importer;
  const aiScene* scene;
  const vector<Mesh> meshes;

public:
  Scene(const string& path);
  const vector<Mesh>& getMeshes() const;
};
