#pragma once

#include <memory>
#include <string>

#include "gl/interfaces/IImage.hpp"

namespace onux {

class Image : public IImage {
public:
    using Ptr = std::unique_ptr<const Image>;

public:
    static Ptr create(const std::string& path);

public:
    ~Image();

    // IImage
    virtual const GLsizei getWidth() const override;
    virtual const GLsizei getHeight() const override;
    virtual const GLvoid* getData() const override;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;

    explicit Image(const std::string& path);
};

} // namespace onux
