#include "utils/removeSubString.hpp"

using String = std::string;

namespace onux {

const String removeSubString(const String& string, const String& subString) {
    String::size_type subStringPosition = string.find(subString);

    return subStringPosition != String::npos
           ? String(string).erase(subStringPosition, subString.length())
           : string;
}

} // namespace onux
