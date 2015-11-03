#include "resources/helpers.hpp"

namespace onux {

template<typename T>
const std::string ResourceLoader<T>::getPath(const std::string& relativePath) const {
  return getDirectory() + relativePath;
}

template<typename T>
void ResourceLoader<T>::loadAll(loadCallback callback) const {
  filesInDirectory(getDirectory(), [&](const std::string& path) {
    callback(path, load(path));
  });
}

template<typename T>
const std::string ResourceLoader<T>::getDirectory() const {
  static const std::string DIRECTORY = "./resources/";
  return DIRECTORY + getSubDirectory();
}

} // namespace onux
