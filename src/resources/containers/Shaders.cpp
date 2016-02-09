#include "resources/containers/Shaders.hpp"

#include "resources/containers/ShaderSources.hpp"
#include "resources/loaders/ShaderLoader.hpp"

namespace onux {

struct Shaders::Impl {
    const ShaderLoader loader;

    Impl(const ShaderSources& shaderSources);
};

Shaders::Shaders(const ShaderSources& shaderSources)
    : impl(new Impl(shaderSources)) {
    load();
}

Shaders::~Shaders() {}

auto Shaders::getLoader() const -> Loader {
    return impl->loader;
}

// Implementation

Shaders::Impl::Impl(const ShaderSources& shaderSources)
    : loader(shaderSources) {}

} // namespace onux
