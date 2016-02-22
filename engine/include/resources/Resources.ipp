#include <stdexcept>

#include "exceptions/Error.hpp"
#include "exceptions/validators/validateNotEmpty.hpp"
#include "resources/utils/filesInDirectory.hpp"
#include "utils/removeSubString.hpp"

namespace onux {

template<typename T>
static void loadResources(
    typename Resources<T>::ResourceMap& resourceMap,
    const std::string&                  directory
) {
    static const std::string DIRECTORY_DELIMITER = "/";

    filesInDirectory(directory, [&](const std::string& path) {
        resourceMap[removeSubString(path, directory + DIRECTORY_DELIMITER)] = T::create(path);
    });
}

template<typename T>
Resources<T>::Resources(const std::string& directory)
    : m_directory(directory) {
    loadResources<T>(m_resourceMap, directory);
}

template<typename T>
const T * const Resources<T>::operator [](const std::string& path) const {
    static const std::string DIRECTORY_DELIMITER = "/";

    validateNotEmpty("path", "Resources<>::operator[]", path);

    try {
        return m_resourceMap.at(path).get();
    }
    catch (const std::out_of_range& _) {
        throw Error(
            "No resource found at \"" +
            m_directory + DIRECTORY_DELIMITER + path +
            "\"!"
        );
    }
}

template<typename T>
void Resources<T>::forEach(ResourceCB resourceCB) const {
    for (const typename ResourceMap::value_type& resourceData : m_resourceMap) {
        resourceCB(
            resourceData.second.get(),
            resourceData.first
        );
    }
}

} // namespace onux
