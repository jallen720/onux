namespace onux {

template<typename T>
ResourceLoader<T>::~ResourceLoader() {
  unload();
}

template<typename T>
void ResourceLoader<T>::load() {
  filesInDirectory(getDirectory(), [&](const std::string& file) {
    m_resources[file] = loadResource(file);
  });
}

template<typename T>
auto ResourceLoader<T>::operator [](const std::string& name) const -> Resource {
  return getFromPath(getDirectory() + name);
}

template<typename T>
const std::string ResourceLoader<T>::getDirectory() const {
  static const std::string DIRECTORY = "./resources/";
  return DIRECTORY + getSubDirectory();
}

template<typename T>
void ResourceLoader<T>::deleteResources() {
  for (auto& resource : m_resources) {
    delete resource.second;
  }
}

template<typename T>
void ResourceLoader<T>::unload() {
  deleteResources();
  m_resources.clear();
}

template<typename T>
auto ResourceLoader<T>::getFromPath(const std::string& path) const -> Resource {
  try {
    return m_resources.at(path);
  } catch (...) {
    throw std::runtime_error("No resource found for \"" + path + "\"!");
  }
}

} // namespace onux
