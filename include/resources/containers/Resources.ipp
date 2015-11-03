#include <stdexcept>

namespace onux {

template<typename T>
Resources<T>::~Resources() {
  unload();
}

template<typename T>
auto Resources<T>::operator [](const std::string& relativePath) const -> Resource {
  return atPath(getLoader().getPath(relativePath));
}

template<typename T>
void Resources<T>::load() {
  getLoader().loadAll([&](const std::string& path, Resource resource) {
    m_resources[path] = resource;
  });
}

template<typename T>
void Resources<T>::deleteResources() {
  for (auto& resource : m_resources) {
    delete resource.second;
  }
}

template<typename T>
void Resources<T>::unload() {
  deleteResources();
  m_resources.clear();
}

template<typename T>
auto Resources<T>::atPath(const std::string& path) const -> Resource {
  try {
    return m_resources.at(path);
  } catch (...) {
    throw std::runtime_error("No resource found for \"" + path + "\"!");
  }
}

} // namespace onux
