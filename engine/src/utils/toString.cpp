#include "utils/toString.hpp"

using std::string;

namespace onux {

template<>
const string toString(bool val) {
    return val == true ? "true" : "false";
}

} // namespace onux
