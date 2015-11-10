#pragma once

#include <memory>
#include <string>

#include "gl/interfaces/IImage.hpp"

namespace onux {

class Image : public IImage {
public:
  Image(const std::string& path);
  ~Image();

  // IImage
  const GLsizei getWidth() const override;
  const GLsizei getHeight() const override;
  const GLvoid* getData() const override;

private:
  struct Impl;
  std::unique_ptr<Impl> impl;
};

} // namespace onux
