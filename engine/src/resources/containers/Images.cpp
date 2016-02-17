#include "resources/containers/Images.hpp"

#include "resources/loaders/ImageLoader.hpp"

namespace onux {

struct Images::Impl {
    const ImageLoader loader;
};

Images::Images()
    : impl(new Impl {}) {
    load();
}

Images::~Images() {}

auto Images::getLoader() const -> Loader {
    return impl->loader;
}

} // namespace onux
