#include "resources/helpers.hpp"

namespace onux {

template<typename T>
const std::string ResourceLoader<T>::getPath(const std::string& relativePath) const {
  return getDirectory() + relativePath;
}

template<typename T>
void ResourceLoader<T>::loadAll(LoadCallback loadCallback) const {
  filesInDirectory(getDirectory(), [&](const std::string& path) {
    loadCallback(path, std::move(load(path)));
  });
}

template<typename T>
const std::string ResourceLoader<T>::getDirectory() const {
  static const std::string DIRECTORY = "./resources/";
  return DIRECTORY + getSubDirectory();
}

} // namespace onux
