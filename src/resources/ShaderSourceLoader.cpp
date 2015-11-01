#include "resources/ShaderSourceLoader.hpp"

using std::string;

namespace onux {

const string& ShaderSourceLoader::getSubDirectory() const {
  static const string SUB_DIRECTORY = "shaders/";
  return SUB_DIRECTORY;
};

auto ShaderSourceLoader::loadResource(const string& path) const -> Resource {
  return new ShaderSource(path);
}

} // namespace onux
