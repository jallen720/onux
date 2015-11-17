#include "graphics/Image.hpp"

#include <Magick++.h>

#include "exceptions/InvalidArg.hpp"

using std::string;

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
    throw InvalidArg(
      "path",
      "Image",
      "\"\"",
      "non-empty"
    );
  }
}

Image::Impl::Impl(const string& path) {
  validatePath(path);
  loadBlob(path);
}

void Image::Impl::loadBlob(const string& path) {
  static const auto FORMAT = "RGBA";
  image.read(path);
  image.flip();
  image.write(&blob, FORMAT);
}

} // namespace onux
