#pragma once

#include <memory>
#include <map>
#include <string>
#include <functional>

namespace onux {

template<typename T>
class UniqueMap {
public:
    using ElementPtr = std::unique_ptr<const T>;
    using ElementCB  = const std::function<void(const T * const, const std::string&)>&;

private:
    using ElementMap = std::map<std::string, ElementPtr>;

public:
    const T * const operator [](const std::string& name) const;
    void add(const std::string& name, ElementPtr element);
    void forEach(ElementCB elementCB) const;

private:
    ElementMap m_elementMap;
};

} // namespace onux

#include "utils/UniqueMap.ipp"


