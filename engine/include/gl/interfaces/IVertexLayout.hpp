#pragma once

#include <vector>
#include <GL/glew.h>

namespace onux {

struct IVertexAttribute;

struct IVertexLayout {
    using Attributes = const std::vector<const IVertexAttribute*>;

    virtual ~IVertexLayout() {}
    virtual Attributes& getAttributes() const = 0;
    virtual const GLsizei getStride() const = 0;
};

} // namespace onux
