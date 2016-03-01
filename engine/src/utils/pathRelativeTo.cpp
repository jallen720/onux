#include "utils/pathRelativeTo.hpp"

using std::string;

namespace onux {

const string pathRelativeTo(const string& directory, const string& path) {
    const size_t directoryPosition = path.rfind(directory);

    return directoryPosition != string::npos
           ? path.substr(directoryPosition + directory.size())
           : path;
}

} // namespace onux
