#pragma once

#include <string>
#include <Magick++.h>

#include "onux_gl/IImage.hpp"

class Image : public onux_gl::IImage {
public:
  Image(const std::string& path);

  // onux_gl::IImage
  const GLsizei getWidth() const override;
  const GLsizei getHeight() const override;
  const GLvoid* getData() const override;

private:
  Magick::Blob  m_blob;
  Magick::Image m_image;

  void loadBlob(const std::string& path);
};
