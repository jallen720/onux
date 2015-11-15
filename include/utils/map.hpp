#pragma once

#include <vector>
#include <algorithm>

namespace onux {

template<typename R, typename T, typename Function>
const std::vector<R> map(const std::vector<T>& container, const Function& function) {
  std::vector<R> result(container.size());

  std::transform(
    container.begin(),
    container.end(),
    result.begin(),
    function
  );

  return result;
}

}
