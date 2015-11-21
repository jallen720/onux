#include "exceptions/messageBuilders/buildArgInfo.hpp"

using std::string;

namespace onux {

const string buildArgInfo(
  const string& argument,
  const string& mustBe
) {
  return ":\n"
         "    was: " + argument + "\n"
         "    must be: " + mustBe;
}

} // namespace onux
