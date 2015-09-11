#include "Image.hpp"

#include <stdexcept>

using std::string;
using std::runtime_error;

static void validatePath(const string& path) {
  if (path.empty()) {
    throw runtime_error("Path to image file is empty!");
  }
}

Image::Image(const string& path) {
  validatePath(path);
  loadBlob(path);
}

const GLsizei Image::getWidth() const {
  return image.columns();
}

const GLsizei Image::getHeight() const {
  return image.rows();
}

const GLvoid* Image::getData() const {
  return blob.data();
}

void Image::loadBlob(const string& path) {
  static const string FORMAT = "RGBA";
  image.read(path);
  image.flip();
  image.write(&blob, FORMAT);
}
