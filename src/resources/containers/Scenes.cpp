#include "resources/containers/Scenes.hpp"

#include "resources/loaders/SceneLoader.hpp"

namespace onux {

struct Scenes::Impl {
    const SceneLoader loader;
};

Scenes::Scenes()
    : impl(new Impl {}) {
    load();
}

Scenes::~Scenes() {}

auto Scenes::getLoader() const -> Loader {
    return impl->loader;
}

} // namespace onux
