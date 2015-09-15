#include "environment/MouseMoveEvent.hpp"

#include <algorithm>

using std::find;

namespace onux {

void MouseMoveEvent::add(const Callback* callback) {
  m_callbacks.push_back(callback);
}

void MouseMoveEvent::remove(const Callback* callback) {
  removeAt(getPosition(callback));
}

void MouseMoveEvent::trigger(const double x, const double y) const {
  for (const Callback* callback : m_callbacks) {
    (*callback)(x, y);
  }
}

auto MouseMoveEvent::getPosition(const Callback* callback) -> Position {
  return find(m_callbacks.begin(), m_callbacks.end(), callback);
}

void MouseMoveEvent::removeAt(Position callbackPosition) {
  if (isValidPosition(callbackPosition)) {
    m_callbacks.erase(callbackPosition);
  }
}

const bool MouseMoveEvent::isValidPosition(Position position) {
  return position != m_callbacks.end();
}

} // namespace onux
