#include "resources/utils/filesInDirectory.hpp"
#include "utils/pathRelativeTo.hpp"

namespace onux {

template<typename T>
UniqueMap<T> loadResources(const std::string& directory) {
    UniqueMap<T> resources;

    filesInDirectory(directory, [&](const std::string& path) {
        resources.add(pathRelativeTo(directory, path), T::create(path));
    });

    return resources;
}

} // namespace onux
