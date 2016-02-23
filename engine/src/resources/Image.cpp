#include "resources/Image.hpp"

#include <Magick++.h>

#include "exceptions/validators/validateNotEmpty.hpp"

using std::string;

namespace onux {

struct Image::Impl {
    Magick::Blob  blob;
    Magick::Image image;

    explicit Impl(const string& path);
    void loadBlob(const string& path);
};

auto Image::create(const string& path) -> Ptr {
    validateNotEmpty("path", "Image::create", path);
    return Ptr(new Image(path));
}

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

Image::Impl::Impl(const string& path) {
    loadBlob(path);
}

void Image::Impl::loadBlob(const string& path) {
    static auto FORMAT = "RGBA";

    image.read(path);
    image.flip();
    image.write(&blob, FORMAT);
}

} // namespace onux
