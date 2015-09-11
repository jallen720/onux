#pragma once

#include <string>
#include <vector>
#include <assimp/Importer.hpp>

class Mesh;
struct aiScene;

class Scene {
public:
  typedef std::vector<const Mesh*> Meshes;

  Scene(const std::string& path);
  ~Scene();
  const Meshes& getMeshes() const;

private:
  Assimp::Importer importer;
  const aiScene* scene;
  const Meshes meshes;

  void deleteMeshes();
};
