#pragma once

#include <map>
#include <string>
#include <functional>

namespace onux {

template<typename T>
class Resources {
public:
    using ResourceMap = std::map<const std::string, typename T::Ptr>;
    using ResourceCB  = const std::function<void(const T*, const std::string&)>&;

public:
    explicit Resources(const std::string& directory);
    const T * const operator [](const std::string& path) const;
    void forEach(ResourceCB resourceCB) const;

private:
    ResourceMap       m_resourceMap;
    const std::string m_directory;
};

} // namespace onux

#include "resources/Resources.ipp"


