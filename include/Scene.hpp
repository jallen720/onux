#pragma once

#include <string>
#include <vector>
#include <assimp/Importer.hpp>
#include "Mesh.hpp"

struct aiScene;

class Scene {
public:
  typedef std::vector<Mesh> Meshes;

  Scene(const std::string& path);
  const Meshes& getMeshes() const;

private:
  Assimp::Importer importer;
  const aiScene* scene;
  const Meshes meshes;
};
