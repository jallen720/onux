#include "resources/utils/filesInDirectory.hpp"

#include <utility>
#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>

using std::string;
using std::function;
using std::make_pair;
using boost::filesystem::recursive_directory_iterator;
using boost::filesystem::path;
using boost::filesystem::is_regular_file;

namespace onux {

void filesInDirectory(const string& directory, const function<void(const string&)> callback) {
  recursive_directory_iterator it(directory), eod;

  BOOST_FOREACH(const path& file, make_pair(it, eod)) {
    if (is_regular_file(file)) {
      callback(file.string());
    }
  }
}

} // namespace onux
