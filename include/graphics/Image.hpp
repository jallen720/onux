#pragma once

#include <string>
#include <Magick++.h>

#include "gl/interfaces/IImage.hpp"

namespace onux {

class Image : public IImage {
public:
  Image(const std::string& path);

  // IImage
  const GLsizei getWidth() const override;
  const GLsizei getHeight() const override;
  const GLvoid* getData() const override;

private:
  Magick::Blob  m_blob;
  Magick::Image m_image;

  void loadBlob(const std::string& path);
};

} // namespace onux
