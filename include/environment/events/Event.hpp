#pragma once

#include <vector>

namespace onux {

template<typename T, typename... Args>
class Event {
protected:
    typedef T* Listener;

private:
    typedef std::vector<Listener> Listeners;

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
