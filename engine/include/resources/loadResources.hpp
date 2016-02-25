#pragma once

#include <string>

#include "utils/UniqueMap.hpp"

namespace onux {

template<typename T>
UniqueMap<T> loadResources(const std::string& directory);

} // namespace onux

#include "resources/loadResources.ipp"
