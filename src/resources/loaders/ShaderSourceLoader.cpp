#include "resources/loaders/ShaderSourceLoader.hpp"

using std::string;

namespace onux {

const string& ShaderSourceLoader::getSubDirectory() const {
    static const string SUB_DIRECTORY = "shaders/";
    return SUB_DIRECTORY;
}

auto ShaderSourceLoader::load(const string& path) const -> Resource {
    return Resource(new ShaderSource(path));
}

} // namespace onux
