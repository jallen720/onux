#include "helpers.hpp"

#include <fstream>
#include <stdexcept>

using std::string;
using std::ifstream;
using std::runtime_error;

namespace onux {

static const char LINE_DELIMITER = '\r';

const string readFile(const string& path) {
  ifstream file;
  file.open(path);

  if (!file.is_open()) {
    throw runtime_error("Failed to open " + path);
  }

  string contents;
  string line;

  // Write all lines in file including newline characters (or else shader will
  // not compile) to contents string.
  while (getline(file, line, LINE_DELIMITER)) {
    contents += line;
  }

  file.close();
  return contents;
}

const string fileExtension(const string& path) {
  const size_t dotPosition = path.find_last_of(".");
  return dotPosition == string::npos ? "" : path.substr(dotPosition + 1);
}

} // namespace onux
