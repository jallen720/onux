#pragma once

#include "resources/containers/Resources.hpp"
#include "resources/loaders/ImageLoader.hpp"
#include "graphics/Image.hpp"

namespace onux {

class Images : public Resources<Image> {
public:
  Images();

protected:
  // Resources
  Loader getLoader() const override;

private:
  const ImageLoader m_loader;
};

} // namespace onux
