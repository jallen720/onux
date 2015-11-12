#include "exceptions/Exception.hpp"

using std::runtime_error;
using std::string;

namespace onux {

static const string createWhat(const string& what) {
  return "ONUX ERROR: " + what;
}

Exception::Exception(const string& what)
  : runtime_error(createWhat(what)) {}

} // namespace onux
