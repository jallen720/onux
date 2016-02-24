#pragma once

#include <memory>
#include <map>
#include <string>
#include <functional>

namespace onux {

template<typename T>
class UniqueMap {
public:
    using ElementMap = std::map<std::string, std::unique_ptr<const T>>;
    using ElementCB  = const std::function<void(const T*, const std::string&)>&;

public:
    UniqueMap(ElementMap elementMap);
    const T * const operator [](const std::string& name) const;
    void forEach(ElementCB elementCB) const;

private:
    const ElementMap m_elementMap;
};

} // namespace onux

#include "utils/UniqueMap.ipp"


