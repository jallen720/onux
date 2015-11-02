#pragma once

#include "resources/loaders/ResourceLoader.hpp"
#include "graphics/Image.hpp"

namespace onux {

class ImageLoader : public ResourceLoader<Image> {
protected:
  // ResourceLoader
  const std::string& getSubDirectory() const override;
  Resource load(const std::string& path) const override;
};

} // namespace onux
