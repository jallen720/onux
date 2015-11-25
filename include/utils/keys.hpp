#pragma once

#include <vector>
#include <map>

#include "utils/transform.hpp"

namespace onux {

template<typename Key, typename Value>
const std::vector<Key> keys(const std::map<const Key, const Value>& map) {
    return transform<Key>(map, [](const auto& pair) {
        return pair.first;
    });
}

} // namespace onux
