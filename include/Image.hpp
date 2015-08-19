#pragma once

#include <string>
#include <Magick++.h>

#include "onux_gl/IImage.hpp"

using std::string;
using Magick::Blob;
using onux_gl::IImage;

class Image : public IImage {
  Blob blob;
  Magick::Image image;

  void loadBlob(const string& path);

public:
  Image(const string& path);

  // IImage
  const GLsizei getWidth() const override;
  const GLsizei getHeight() const override;
  const GLvoid* getData() const override;
};
