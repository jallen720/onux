#pragma once

#include <string>

#include "utils/UniqueMap.hpp"

namespace onux {

template<typename T>
class Resources : public UniqueMap<T> {
public:
    explicit Resources(const std::string& directory);
};

} // namespace onux

#include "resources/Resources.ipp"


