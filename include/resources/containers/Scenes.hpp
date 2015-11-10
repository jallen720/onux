#pragma once

#include <memory>

#include "resources/containers/Resources.hpp"
#include "graphics/Scene.hpp"

namespace onux {

class Scenes : public Resources<const Scene> {
public:
  Scenes();
  ~Scenes();

protected:
  // Resources
  Loader getLoader() const override;

private:
  struct Impl;
  std::unique_ptr<Impl> impl;
};

} // namespace onux
