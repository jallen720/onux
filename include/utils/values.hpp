#pragma once

#include <vector>
#include <map>

#include "utils/transform.hpp"

namespace onux {

template<typename Key, typename Value>
const std::vector<Value> values(const std::map<const Key, const Value>& map) {
    return transform<Value>(map, [](const std::pair<const Key, const Value>& pair) {
        return pair.second;
    });
}

template<typename Key, typename Value>
const std::vector<Value> values(const std::map<const Key, Value>& map) {
    return transform<Value>(map, [](const std::pair<const Key, Value>& pair) {
        return pair.second;
    });
}

} // namespace onux
