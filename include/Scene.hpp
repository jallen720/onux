#pragma once

#include <string>
#include <vector>
#include <assimp/Importer.hpp>
#include "Mesh.hpp"

struct aiScene;

namespace onux {

class Scene {
public:
  typedef std::vector<Mesh> Meshes;

  Scene(const std::string& path);
  const Meshes& getMeshes() const;

private:
  Assimp::Importer m_importer;
  const aiScene*   m_scene;
  const Meshes     m_meshes;
};

} // namespace onux
