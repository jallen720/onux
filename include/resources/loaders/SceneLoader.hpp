#pragma once

#include "resources/loaders/ResourceLoader.hpp"
#include "graphics/Scene.hpp"

namespace onux {

class SceneLoader : public ResourceLoader<const Scene> {
protected:
  // ResourceLoader
  const std::string& getSubDirectory() const override;
  Resource load(const std::string& path) const override;
};

} // namespace onux
