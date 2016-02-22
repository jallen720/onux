#pragma once

#include <memory>
#include <map>

#include "gl/GLData.hpp"

namespace onux {

struct IImage;

class Texture : public GLData {
public:
    using Ptr     = std::unique_ptr<const Texture>;
    using Options = const std::map<const GLenum, const GLint>;

private:
    static Options DEFAULT_OPTIONS;

public:
    static Ptr create(const IImage* image, Options& options = DEFAULT_OPTIONS);

public:
    ~Texture();
    void bind(const GLuint unit) const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;

    explicit Texture(const IImage* image, Options& options, const GLuint id);
};

} // namespace onux
