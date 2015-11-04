#pragma once

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
  void loadData() const override;

private:
  const IVertexLayout& m_layout;

  void defineLayout() const;
};

} // namespace onux
