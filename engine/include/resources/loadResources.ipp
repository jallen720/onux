#include "resources/utils/filesInDirectory.hpp"
#include "utils/removeSubString.hpp"

namespace onux {

template<typename T>
typename UniqueMap<T>::ElementMap loadResources(const std::string& directory) {
    static const std::string DIRECTORY_DELIMITER = "/";

    typename UniqueMap<T>::ElementMap resourceMap;

    filesInDirectory(directory, [&](const std::string& path) {
        resourceMap[removeSubString(path, directory + DIRECTORY_DELIMITER)] = T::create(path);
    });

    return resourceMap;
}

} // namespace onux
