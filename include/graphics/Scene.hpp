#pragma once

#include <memory>
#include <string>
#include <vector>
#include "graphics/Mesh.hpp"

struct aiScene;

namespace onux {

class Scene {
public:
  typedef std::vector<Mesh> Meshes;

public:
  Scene(const std::string& path);
  ~Scene();
  const Meshes& getMeshes() const;

private:
  struct Impl;
  std::unique_ptr<Impl> impl;
};

} // namespace onux
