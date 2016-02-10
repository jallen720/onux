#pragma once

#include <map>
#include <string>

#include "resources/loaders/ResourceLoader.hpp"

namespace onux {

template<typename T>
class Resources {
protected:
    using Loader = const ResourceLoader<T>&;

private:
    using Resource = typename ResourceLoader<T>::Resource;
    using ResourceMap = std::map<const std::string, Resource>;

public:
    virtual ~Resources();
    T* operator [](const std::string& relativePath) const;

protected:
    void load();
    virtual Loader getLoader() const = 0;

private:
    ResourceMap m_resources;

    T* atPath(const std::string& path) const;
};

} // namespace onux

#include "resources/containers/Resources.ipp"


