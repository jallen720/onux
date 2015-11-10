#pragma once

#include <memory>

#include "resources/containers/Resources.hpp"
#include "graphics/Scene.hpp"

namespace onux {

class Models : public Resources<Scene> {
public:
  Models();
  ~Models();

protected:
  // Resources
  Loader getLoader() const override;

private:
  struct Impl;
  std::unique_ptr<Impl> impl;
};

} // namespace onux
