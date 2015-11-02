#pragma once

#include <string>
#include <functional>

namespace onux {

template<typename T>
class ResourceLoader {
public:
  typedef const T* Resource;

private:
  typedef const std::function<void(const std::string&, Resource)>& loadCallback;

public:
  virtual ~ResourceLoader() {}
  const std::string getPath(const std::string& relativePath) const;
  void loadAll(loadCallback callback) const;

protected:
  virtual const std::string& getSubDirectory() const = 0;
  virtual Resource load(const std::string& path) const = 0;

private:
  const std::string getDirectory() const;
};

} // namespace onux

#include "resources/loaders/ResourceLoader.ipp"


