#pragma once

#include <vector>
#include <map>

#include "utils/map.hpp"

namespace onux {

template<typename T, typename _>
const std::vector<T> keys(const std::map<const T, const _>& map) {
  return onux::map<T>(map, [](const auto& pair) {
    return pair.first;
  });
}

} // namespace onux
