#pragma once

namespace onux {

struct IInput {
    virtual ~IInput() {}
    virtual void cursorPosEvent(const double x, const double y) = 0;
};

} // namespace onux
