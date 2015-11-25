#pragma once

#include <vector>
#include <algorithm>

namespace onux {

template<typename T, typename Predicate>
const bool existsIn(const std::vector<T>& container, const Predicate& predicate) {
    return std::find_if(
        container.begin(),
        container.end(),
        predicate
    ) != container.end();
}

}
