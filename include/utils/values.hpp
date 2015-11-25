#pragma once

#include <vector>
#include <map>

#include "utils/transform.hpp"

namespace onux {

template<typename Key, typename Value>
const std::vector<Value> values(const std::map<const Key, const Value>& map) {
    return transform<Value>(map, [](const auto& pair) {
        return pair.second;
    });
}

} // namespace onux
