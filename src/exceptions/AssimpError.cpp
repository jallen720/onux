#include "exceptions/AssimpError.hpp"

using std::string;

namespace onux {

static const string createWhat(const string& what) {
  return "ASSIMP ERROR: " + what;
}

AssimpError::AssimpError(const string& what)
  : Exception(createWhat(what)) {}

} // namespace onux
