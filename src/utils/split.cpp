#include "utils/split.hpp"

#include <sstream>

using std::vector;
using std::stringstream;
using std::getline;

namespace onux {

vector<std::string> split(const std::string& string, const char delimiter) {
    vector<std::string> elements;
    stringstream stream(string);
    std::string element;

    while (getline(stream, element, delimiter)) {
        elements.push_back(element);
    }

    return elements;
}

} // namespace onux
