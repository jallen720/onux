#pragma once

#include "resources/containers/Resources.hpp"
#include "resources/loaders/ShaderSourceLoader.hpp"
#include "graphics/ShaderSource.hpp"

namespace onux {

class ShaderSources : public Resources<ShaderSource> {
public:
  ShaderSources();

protected:
  // Resources
  Loader getLoader() const override;

private:
  const ShaderSourceLoader m_loader;
};

} // namespace onux
