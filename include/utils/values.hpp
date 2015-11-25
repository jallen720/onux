#pragma once

#include <vector>
#include <map>

#include "utils/map.hpp"

namespace onux {

template<typename Key, typename Value>
const std::vector<Value> values(const std::map<const Key, const Value>& map) {
    return onux::map<Value>(map, [](const auto& pair) {
        return pair.second;
    });
}

} // namespace onux
