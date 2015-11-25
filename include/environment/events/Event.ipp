#include <algorithm>

namespace onux {

template<typename T, typename... Args>
void Event<T, Args...>::add(Listener listener) {
    m_listeners.push_back(listener);
}

template<typename T, typename... Args>
void Event<T, Args...>::remove(Listener listener) {
    m_listeners.erase(
        std::remove(m_listeners.begin(), m_listeners.end(), listener),
        m_listeners.end()
    );
}

template<typename T, typename... Args>
auto Event<T, Args...>::getListeners() -> Listeners& {
    return m_listeners;
}

} // namespace onux
