#pragma once

#include <GL/glew.h>

namespace onux {

struct IBufferData {
    virtual ~IBufferData() {}
    virtual const size_t getCount() const = 0;
    virtual const GLsizei getSize() const = 0;
    virtual const GLvoid* getPointer() const = 0;
};

} // namespace onux
