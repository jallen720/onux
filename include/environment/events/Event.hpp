#pragma once

#include <vector>

namespace onux {

template<typename T, typename... Args>
class Event {
protected:
    using Listener = T*;

private:
    using Listeners = std::vector<Listener>;

public:
    virtual ~Event() {}
    void add(Listener listener);
    void remove(Listener listener);
    Listeners& getListeners();
    virtual void trigger(Args... args) = 0;

private:
    Listeners m_listeners;
};

} // namespace onux

#include "environment/events/Event.ipp"
