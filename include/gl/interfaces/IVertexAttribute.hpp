#pragma once

#include <GL/glew.h>

namespace onux {

struct IVertexAttribute {
    virtual ~IVertexAttribute() {}
    virtual const GLint getElementCount() const = 0;
    virtual const GLenum getType() const = 0;
    virtual const GLboolean getIsNormalized() const = 0;
    virtual const GLvoid* getOffset() const = 0;
    virtual const GLsizei getSize() const = 0;
};

} // namespace onux
