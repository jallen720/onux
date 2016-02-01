#include "resources/containers/Models.hpp"

#include "resources/loaders/ModelLoader.hpp"

namespace onux {

struct Models::Impl {
    const ModelLoader loader;
};

Models::Models()
    : impl(new Impl {}) {
    load();
}

Models::~Models() {}

auto Models::getLoader() const -> Loader {
    return impl->loader;
}

} // namespace onux
