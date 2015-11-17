#include <memory>

#include "exceptions/Error.hpp"

namespace onux {

template<typename T>
Resources<T>::~Resources() {}

template<typename T>
T* Resources<T>::operator [](const std::string& relativePath) const {
  return atPath(getLoader().getPath(relativePath));
}

template<typename T>
void Resources<T>::load() {
  getLoader().loadAll([&](const std::string& path, Resource resource) {
    m_resources[path] = std::move(resource);
  });
}

template<typename T>
T* Resources<T>::atPath(const std::string& path) const {
  try {
    return m_resources.at(path).get();
  } catch (...) {
    throw Error("No resource found at \"" + path + "\"!");
  }
}

} // namespace onux
