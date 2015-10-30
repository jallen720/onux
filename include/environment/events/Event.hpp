#pragma once

#include <vector>
#include <algorithm>

namespace onux {

template<typename T, typename... Args>
class Event {
protected:
  typedef T* Listener;

private:
  typedef std::vector<Listener> Listeners;

  Listeners m_listeners;

public:
  void add(Listener listener) {
    m_listeners.push_back(listener);
  }

  void remove(Listener listener) {
    m_listeners.erase(
      std::remove(m_listeners.begin(), m_listeners.end(), listener),
      m_listeners.end()
    );
  }

  Listeners& getListeners() {
    return m_listeners;
  }

  virtual void trigger(Args... args) = 0;
};

} // namespace onux
