#include "graphics/Image.hpp"

#include <stdexcept>
#include <Magick++.h>

using std::string;
using std::runtime_error;

namespace onux {

struct Image::Impl {
  Magick::Blob  blob;
  Magick::Image image;

  void loadBlob(const string& path);
};

static void validatePath(const string& path) {
  if (path.empty()) {
    throw runtime_error("Path to image file is empty!");
  }
}

Image::Image(const string& path)
  : impl(new Impl()) {
  validatePath(path);
  impl->loadBlob(path);
}

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

void Image::Impl::loadBlob(const string& path) {
  static const string FORMAT = "RGBA";
  image.read(path);
  image.flip();
  image.write(&blob, FORMAT);
}

} // namespace onux
