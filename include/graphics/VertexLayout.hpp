#pragma once

#include <memory>

#include "gl/interfaces/IVertexLayout.hpp"

namespace onux {

class VertexLayout : public IVertexLayout {
public:
  VertexLayout(Attributes& attributes);
  ~VertexLayout();

  // IVertexLayout
  Attributes& getAttributes() const override;
  const GLsizei getStride() const override;

private:
  struct Impl;
  std::unique_ptr<Impl> impl;
};

} // namespace onux
