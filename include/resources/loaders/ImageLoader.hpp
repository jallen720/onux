#pragma once

#include "resources/loaders/ResourceLoader.hpp"
#include "graphics/Image.hpp"

namespace onux {

class ImageLoader : public ResourceLoader<const Image> {
protected:
  // ResourceLoader
  virtual const std::string& getSubDirectory() const override;
  virtual Resource load(const std::string& path) const override;
};

} // namespace onux
