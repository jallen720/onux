#include "graphics/Image.hpp"

#include <stdexcept>
#include <Magick++.h>

using std::string;
using std::runtime_error;

namespace onux {

struct Image::Impl {
  Magick::Blob  blob;
  Magick::Image image;

  Impl(const string& path);
  void loadBlob(const string& path);
};

Image::Image(const string& path)
  : impl(new Impl(path)) {}

Image::~Image() {}

const GLsizei Image::getWidth() const {
  return impl->image.columns();
}

const GLsizei Image::getHeight() const {
  return impl->image.rows();
}

const GLvoid* Image::getData() const {
  return impl->blob.data();
}

// Implementation

static void validatePath(const string& path) {
  if (path.empty()) {
    throw runtime_error("Path to image file is empty!");
  }
}

Image::Impl::Impl(const string& path) {
  validatePath(path);
  loadBlob(path);
}

void Image::Impl::loadBlob(const string& path) {
  static const string FORMAT = "RGBA";
  image.read(path);
  image.flip();
  image.write(&blob, FORMAT);
}

} // namespace onux
