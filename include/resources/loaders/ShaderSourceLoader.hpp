#pragma once

#include "resources/loaders/ResourceLoader.hpp"
#include "graphics/ShaderSource.hpp"

namespace onux {

class ShaderSourceLoader : public ResourceLoader<ShaderSource> {
protected:
  // ResourceLoader
  const std::string& getSubDirectory() const override;
  Resource load(const std::string& path) const override;
};

} // namespace onux
