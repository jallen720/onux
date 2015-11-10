#include "resources/containers/ShaderSources.hpp"

#include "resources/loaders/ShaderSourceLoader.hpp"

namespace onux {

struct ShaderSources::Impl {
  const ShaderSourceLoader loader;
};

ShaderSources::ShaderSources()
  : impl(new Impl()) {
  load();
}

ShaderSources::~ShaderSources() {}

auto ShaderSources::getLoader() const -> Loader {
  return impl->loader;
}

} // namespace onux
