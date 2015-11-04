#pragma once

#include "gl/interfaces/IVertexLayout.hpp"

namespace onux {

class VertexLayout : public IVertexLayout {
public:
  VertexLayout(Attributes& attributes);

  // IVertexLayout
  Attributes& getAttributes() const override;
  const GLsizei getStride() const override;

private:
  Attributes    m_attributes;
  const GLsizei m_stride;
};

} // namespace onux
