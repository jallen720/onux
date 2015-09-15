#pragma once

#include <vector>
#include <functional>

#include "environment/Input.hpp"

namespace onux {

class MouseMoveEvent {
public:
  typedef std::function<void(const double, const double)> Callback;

  void add(const Callback* callback);
  void remove(const Callback* callback);
  void trigger(const double x, const double y) const;

private:
  typedef std::vector<const Callback*> Callbacks;
  typedef const Callbacks::iterator Position;

  Callbacks m_callbacks;

  Position getPosition(const Callback* callback);
  void removeAt(Position position);
  const bool isValidPosition(Position position);
};

} // namespace onux
