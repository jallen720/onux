#pragma once

#include <vector>
#include <algorithm>

namespace onux {

template<typename T, typename Container, typename Function>
const std::vector<T> map(
    const Container& container,
    const Function&    function
) {
    std::vector<T> result(container.size());

    std::transform(
        container.begin(),
        container.end(),
        result.begin(),
        function
    );

    return result;
}

}
