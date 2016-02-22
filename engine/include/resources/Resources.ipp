#include "resources/utils/filesInDirectory.hpp"
#include "utils/removeSubString.hpp"

namespace onux {

template<typename T>
static void loadResources(
    typename UniqueMap<T>::ElementMap& resourceMap,
    const std::string&                 directory
) {
    static const std::string DIRECTORY_DELIMITER = "/";

    filesInDirectory(directory, [&](const std::string& path) {
        resourceMap[removeSubString(path, directory + DIRECTORY_DELIMITER)] = T::create(path);
    });
}

template<typename T>
Resources<T>::Resources(const std::string& directory) {
    loadResources<T>(UniqueMap<T>::getElementMap(), directory);
}

} // namespace onux
