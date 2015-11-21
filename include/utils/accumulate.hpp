#pragma once

#include <vector>
#include <algorithm>

namespace onux {

template<typename T, typename Container, typename Function>
T accumulate(
  const T&         initialValue,
  const Container& container,
  const Function&  function
) {
  return std::accumulate(
    container.begin(),
    container.end(),
    initialValue,
    function
  );
}

}
