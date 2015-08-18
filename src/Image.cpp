#include "Image.hpp"

#include <stdexcept>

using std::runtime_error;

static void validatePath(const string& path) {
  if (path.empty())
    throw runtime_error("Path to image file is empty!");
}

void Image::loadBlob(const string& path) {
  static const string FORMAT = "RGBA";
  Magick::Image image;
  image.read(path);
  image.flip();
  image.write(&blob, FORMAT);
}

Image::Image(const string& path) {
  validatePath(path);
  loadBlob(path);
}
