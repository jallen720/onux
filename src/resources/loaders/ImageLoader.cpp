#include "resources/loaders/ImageLoader.hpp"

using std::string;

namespace onux {

const string& ImageLoader::getSubDirectory() const {
  static const string SUB_DIRECTORY = "images/";
  return SUB_DIRECTORY;
}

auto ImageLoader::load(const string& path) const -> Resource {
  return new Image(path);
}

} // namespace onux
