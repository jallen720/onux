#pragma once

#include <string>
#include <GL/glew.h>
#include <Magick++.h>

using std::string;
using Magick::Blob;

class Image {
  Blob blob;
  Magick::Image image;

  void loadBlob(const string& path);

public:
  Image(const string& path);
  const GLsizei getWidth() const;
  const GLsizei getHeight() const;
  const GLvoid* getData() const;
};
