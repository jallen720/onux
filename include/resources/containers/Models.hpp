#pragma once

#include "resources/containers/Resources.hpp"
#include "resources/loaders/ModelLoader.hpp"
#include "graphics/Scene.hpp"

namespace onux {

class Models : public Resources<Scene> {
public:
  Models();

protected:
  // Resources
  const Loader& getLoader() const override;

private:
  const ModelLoader m_loader;
};

} // namespace onux
