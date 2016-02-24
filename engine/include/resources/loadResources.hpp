#pragma once

#include <string>

#include "utils/UniqueMap.hpp"

namespace onux {

template<typename T>
typename UniqueMap<T>::ElementMap loadResources(const std::string& directory);

} // namespace onux

#include "resources/loadResources.ipp"
