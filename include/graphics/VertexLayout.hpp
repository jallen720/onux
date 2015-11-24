#pragma once

#include <memory>

#include "gl/interfaces/IVertexLayout.hpp"

namespace onux {

class VertexLayout : public IVertexLayout {
public:
  explicit VertexLayout(Attributes& attributes);
  ~VertexLayout();

  // IVertexLayout
  virtual Attributes& getAttributes() const override;
  virtual const GLsizei getStride() const override;

private:
  struct Impl;
  std::unique_ptr<Impl> impl;
};

} // namespace onux
