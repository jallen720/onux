#pragma once

#include <vector>
#include <algorithm>
#include <functional>

namespace onux {

template<typename... Args>
class Event {
public:
  typedef std::function<void(Args...)> Callback;

private:
  typedef std::vector<const Callback*> Callbacks;
  typedef const typename Callbacks::iterator Position;

  Callbacks m_callbacks;

  Position getPosition(const Callback* callback) {
    return std::find(m_callbacks.begin(), m_callbacks.end(), callback);
  }

  const bool isValidPosition(Position position) {
    return position != m_callbacks.end();
  }

  void removeAt(Position position) {
    if (isValidPosition(position)) {
      m_callbacks.erase(position);
    }
  }

public:
  void add(const Callback* callback) {
    m_callbacks.push_back(callback);
  }

  void remove(const Callback* callback) {
    removeAt(getPosition(callback));
  }

  void trigger(Args... args) const{
    for (const Callback* callback : m_callbacks) {
      (*callback)(args...);
    }
  }
};

} // namespace onux
