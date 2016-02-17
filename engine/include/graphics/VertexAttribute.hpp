#pragma once

#include <memory>
#include <GL/glew.h>

#include "gl/interfaces/IVertexAttribute.hpp"

namespace onux {

class VertexAttribute : public IVertexAttribute {
public:
    VertexAttribute(
        const GLint     elementCount,
        const GLenum    type,
        const GLboolean isNormalized,
        const GLvoid*   offset,
        const GLsizei   size
    );
    ~VertexAttribute();
    const GLint getElementCount() const;
    const GLenum getType() const;
    const GLboolean getIsNormalized() const;
    const GLvoid* getOffset() const;
    const GLsizei getSize() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
