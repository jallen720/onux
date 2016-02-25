#include "resources/utils/filesInDirectory.hpp"
#include "utils/removeSubString.hpp"

namespace onux {

template<typename T>
UniqueMap<T> loadResources(const std::string& directory) {
    static const std::string DIRECTORY_DELIMITER = "/";

    UniqueMap<T> resources;

    filesInDirectory(directory, [&](const std::string& path) {
        resources.add(
            removeSubString(path, directory + DIRECTORY_DELIMITER),
            T::create(path)
        );
    });

    return resources;
}

} // namespace onux
