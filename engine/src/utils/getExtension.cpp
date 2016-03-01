#include "utils/getExtension.hpp"

using std::string;

namespace onux {

const string getExtension(const string& path) {
    const size_t dotPosition = path.find_last_of('.');

    return dotPosition != string::npos
           ? path.substr(dotPosition + 1)
           : "";
}

} // namespace onux
