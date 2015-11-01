#pragma once

#include "resources/ResourceLoader.hpp"
#include "graphics/ShaderSource.hpp"

namespace onux {

class ShaderSourceLoader : public ResourceLoader<ShaderSource> {
protected:
  // ResourceLoader
  const std::string& getSubDirectory() const override;
  Resource loadResource(const std::string& path) const override;
};

} // namespace onux
