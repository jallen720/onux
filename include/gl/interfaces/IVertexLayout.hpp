#pragma once

#include <vector>
#include <GL/glew.h>

namespace onux {

struct IVertexAttribute;

struct IVertexLayout {
    typedef const std::vector<const IVertexAttribute*> Attributes;

    virtual ~IVertexLayout() {}
    virtual Attributes& getAttributes() const = 0;
    virtual const GLsizei getStride() const = 0;
};

} // namespace onux
