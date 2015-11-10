#pragma once

#include <memory>

#include "resources/containers/Resources.hpp"
#include "graphics/Image.hpp"

namespace onux {

class Images : public Resources<const Image> {
public:
  Images();
  ~Images();

protected:
  // Resources
  Loader getLoader() const override;

private:
  struct Impl;
  std::unique_ptr<Impl> impl;
};

} // namespace onux
