#include "resources/loaders/ModelLoader.hpp"

using std::string;

namespace onux {

const string& ModelLoader::getSubDirectory() const {
    static const string SUB_DIRECTORY = "models/";
    return SUB_DIRECTORY;
}

auto ModelLoader::load(const string& path) const -> Resource {
    return Resource(new Model(path));
}

} // namespace onux
