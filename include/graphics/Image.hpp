#pragma once

#include <memory>
#include <string>

#include "gl/interfaces/IImage.hpp"

namespace onux {

class Image : public IImage {
public:
  explicit Image(const std::string& path);
  ~Image();

  // IImage
  virtual const GLsizei getWidth() const override;
  virtual const GLsizei getHeight() const override;
  virtual const GLvoid* getData() const override;

private:
  struct Impl;
  std::unique_ptr<Impl> impl;
};

} // namespace onux
