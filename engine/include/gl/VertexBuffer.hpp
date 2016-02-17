#pragma once

#include <memory>

#include "gl/BufferObject.hpp"

namespace onux {

struct IVertexLayout;
struct IBufferData;

class VertexBuffer : public BufferObject {
public:
    VertexBuffer(
        const IVertexLayout& layout,
        const IBufferData&   data,
        const GLenum         usage = GL_STATIC_DRAW
    );
    ~VertexBuffer();

    // BufferObject
    virtual void loadData() const override;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
