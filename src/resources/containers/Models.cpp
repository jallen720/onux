#include "resources/containers/Models.hpp"

namespace onux {

Models::Models() {
  load();
}

auto Models::getLoader() const -> const Loader& {
  return m_loader;
}

} // namespace onux
