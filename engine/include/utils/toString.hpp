#pragma once

#include <string>

namespace onux {

template<typename T>
const std::string toString(T val) {
    return std::to_string(val);
}

template<>
const std::string toString(bool val);

} // namespace onux
