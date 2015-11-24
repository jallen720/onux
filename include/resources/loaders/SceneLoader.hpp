#pragma once

#include "resources/loaders/ResourceLoader.hpp"
#include "graphics/Scene.hpp"

namespace onux {

class SceneLoader : public ResourceLoader<const Scene> {
protected:
  // ResourceLoader
  virtual const std::string& getSubDirectory() const override;
  virtual Resource load(const std::string& path) const override;
};

} // namespace onux
