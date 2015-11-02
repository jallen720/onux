#pragma once

#include <map>
#include <string>

#include "resources/ResourceLoader.hpp"

namespace onux {

template<typename T>
class Resources {
private:
  typedef ResourceLoader<T> Loader;
  typedef typename Loader::Resource Resource;
  typedef std::map<const std::string, Resource> ResourceMap;

public:
  Resources(const Loader& loader);
  ~Resources();
  Resource operator [](const std::string& relativePath) const;

private:
  const Loader& m_loader;
  ResourceMap   m_resources;

  void load();
  void deleteResources();
  void unload();
  Resource atPath(const std::string& path) const;
};

} // namespace onux

#include "Resources.ipp"


