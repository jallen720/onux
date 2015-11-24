#pragma once

#include "resources/loaders/ResourceLoader.hpp"
#include "graphics/ShaderSource.hpp"

namespace onux {

class ShaderSourceLoader : public ResourceLoader<const ShaderSource> {
protected:
  // ResourceLoader
  virtual const std::string& getSubDirectory() const override;
  virtual Resource load(const std::string& path) const override;
};

} // namespace onux
