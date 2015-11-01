#pragma once

#include <map>
#include <string>
#include <stdexcept>

#include "resources/helpers.hpp"

namespace onux {

template<typename T>
class ResourceLoader {
protected:
  typedef const T* Resource;

public:
  virtual ~ResourceLoader();
  void load();
  Resource operator [](const std::string& name) const;

protected:
  virtual const std::string& getSubDirectory() const = 0;
  virtual Resource loadResource(const std::string& path) const = 0;

private:
  std::map<const std::string, Resource> m_resources;

  const std::string getDirectory() const;
  void deleteResources();
  void unload();
  Resource getFromPath(const std::string& path) const;
};

} // namespace onux

#include "ResourceLoader.ipp"


