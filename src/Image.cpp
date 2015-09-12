#include "Image.hpp"

#include <stdexcept>

using std::string;
using std::runtime_error;

namespace onux {

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
  return m_image.columns();
}

const GLsizei Image::getHeight() const {
  return m_image.rows();
}

const GLvoid* Image::getData() const {
  return m_blob.data();
}

void Image::loadBlob(const string& path) {
  static const string FORMAT = "RGBA";
  m_image.read(path);
  m_image.flip();
  m_image.write(&m_blob, FORMAT);
}

} // namespace onux
