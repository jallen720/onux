#pragma once

#include <vector>
#include <algorithm>

namespace onux {

template<typename Container, typename Predicate>
const bool existsIn(const Container& container, const Predicate& predicate) {
    return std::find_if(
        container.begin(),
        container.end(),
        predicate
    ) != container.end();
}

}
