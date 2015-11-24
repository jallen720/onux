#include "utils/readFile.hpp"

#include <fstream>
#include <functional>

#include "exceptions/Error.hpp"

using std::string;
using std::ifstream;
using std::function;

namespace onux {

static const char LINE_DELIMITER = '\r';

static void validateFile(const ifstream& file, const string& path) {
  if (!file.is_open()) {
    throw Error("Failed to open " + path);
  }
}

static void useFile(const string& path, const function<void(ifstream& file)>& callback) {
  ifstream file(path);
  validateFile(file, path);
  callback(file);
  file.close();
}

static void readLines(const string& path, const function<void(const string& line)>& callback) {
  useFile(path, [&](ifstream& file) {
    string line;

    while (getline(file, line, LINE_DELIMITER)) {
      callback(line);
    }
  });
}

const string readFile(const string& path) {
  string contents;

  readLines(path, [&](const string& line) {
    contents += line;
  });

  return contents;
}

} // namespace onux
