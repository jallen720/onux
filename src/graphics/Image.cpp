#include "graphics/Image.hpp"

#include <Magick++.h>

#include "exceptions/EmptyStringArg.hpp"

using std::string;

namespace onux {

struct Image::Impl {
  Magick::Blob  blob;
  Magick::Image image;

  Impl(const string& path);
  void loadBlob(const string& path);
};

static void validatePath(const string& path) {
  if (path.empty()) {
    throw EmptyStringArg("path", "Image");
  }
}

static const string& getValidPath(const string& path) {
  validatePath(path);
  return path;
}

Image::Image(const string& path)
  : impl(new Impl(getValidPath(path))) {}

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

Image::Impl::Impl(const string& path) {
  loadBlob(path);
}

void Image::Impl::loadBlob(const string& path) {
  static const auto FORMAT = "RGBA";
  image.read(path);
  image.flip();
  image.write(&blob, FORMAT);
}

} // namespace onux
