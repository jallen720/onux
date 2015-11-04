#include "resources/containers/ShaderSources.hpp"

namespace onux {

ShaderSources::ShaderSources() {
  load();
}

auto ShaderSources::getLoader() const -> Loader {
  return m_loader;
}

} // namespace onux
