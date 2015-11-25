#pragma once

#include <vector>
#include <algorithm>

namespace onux {

template<typename T>
const bool contains(const std::vector<T>& container, const T& item) {
    return std::find(
        container.begin(),
        container.end(),
        item
    ) != container.end();
}

}
