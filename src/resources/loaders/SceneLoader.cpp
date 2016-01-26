#include "resources/loaders/SceneLoader.hpp"

using std::string;

namespace onux {

const string& SceneLoader::getSubDirectory() const {
    static const string SUB_DIRECTORY = "scenes/";
    return SUB_DIRECTORY;
}

auto SceneLoader::load(const string& path) const -> Resource {
    return Resource(new Scene(path));
}

} // namespace onux
