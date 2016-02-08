#pragma once

#include <vector>
#include <map>
#include <algorithm>

namespace onux {

template<typename Container, typename T>
const bool contains(const Container& container, const T& item) {
    return std::find(
        container.begin(),
        container.end(),
        item
    ) != container.end();
}

template<typename T, typename _>
const bool contains(const std::map<const T, _>& container, const T& item) {
    return container.find(item) != container.end();
}

template<typename T, typename _>
const bool contains(const std::map<T, _>& container, T& item) {
    return container.find(item) != container.end();
}

}
