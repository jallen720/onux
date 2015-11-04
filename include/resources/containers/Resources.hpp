#pragma once

#include <map>
#include <string>

#include "resources/loaders/ResourceLoader.hpp"

namespace onux {

template<typename T>
class Resources {
protected:
  typedef const ResourceLoader<T>& Loader;

private:
  typedef typename ResourceLoader<T>::Resource Resource;
  typedef std::map<const std::string, Resource> ResourceMap;

public:
  virtual ~Resources();
  Resource operator [](const std::string& relativePath) const;

protected:
  void load();
  virtual Loader getLoader() const = 0;

private:
  ResourceMap m_resources;

  void deleteResources();
  void unload();
  Resource atPath(const std::string& path) const;
};

} // namespace onux

#include "resources/containers/Resources.ipp"


