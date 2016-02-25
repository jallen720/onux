#include <stdexcept>

#include "exceptions/Error.hpp"
#include "exceptions/validators/validateNotEmpty.hpp"

namespace onux {

template<typename T>
const T * const UniqueMap<T>::operator [](const std::string& name) const {
    validateNotEmpty("name", "UniqueMap<>::operator[]", name);

    try {
        return m_elementMap.at(name).get();
    }
    catch (const std::out_of_range& _) {
        throw Error("No element found for name \"" + name + "\"");
    }
}

template<typename T>
void UniqueMap<T>::add(const std::string& name, ElementPtr element) {
    m_elementMap[name] = std::move(element);
}

template<typename T>
void UniqueMap<T>::forEach(ElementCB elementCB) const {
    for (const typename ElementMap::value_type& element : m_elementMap) {
        elementCB(
            element.second.get(),
            element.first
        );
    }
}

} // namespace onux
