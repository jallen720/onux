#include "resources/containers/Images.hpp"

namespace onux {

Images::Images() {
  load();
}

auto Images::getLoader() const -> const Loader& {
  return m_loader;
}

} // namespace onux
