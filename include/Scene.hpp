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
public:
  typedef const vector<const Mesh*> Meshes;

private:
  Importer importer;
  const aiScene* scene;
  Meshes meshes;

  void deleteMeshes();

public:
  Scene(const string& path);
  ~Scene();
  Meshes& getMeshes() const;
};
