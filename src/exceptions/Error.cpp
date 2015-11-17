#include "exceptions/Error.hpp"

using std::runtime_error;
using std::string;

namespace onux {

static const string createWhat(const string& what) {
  return "ONUX ERROR: " + what;
}

Error::Error(const string& what)
  : runtime_error(createWhat(what)) {}

} // namespace onux
