#include "exceptions/messageBuilders/buildArgInfo.hpp"

using std::string;

namespace onux {

const string buildArgInfo(const string& mustBe) {
    return ":\n"
           "    must be: " + mustBe;
}

} // namespace onux
