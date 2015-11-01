#include "resources/helpers.hpp"

#include <boost/filesystem.hpp>

using std::string;
using std::function;
using boost::filesystem::recursive_directory_iterator;
using boost::filesystem::path;
using boost::filesystem::is_directory;

namespace onux {

void recursiveFileList(
  const string& baseDir,
  const function<void(const string&)> callback
) {
  typedef recursive_directory_iterator iterator;

  for (iterator end, currentDir(baseDir); currentDir != end; ++currentDir) {
    const path& file = currentDir->path();

    if (!is_directory(file)) {
      callback(file.string());
    }
  }
}

} // namespace onux
