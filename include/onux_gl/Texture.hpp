#pragma once

#include <map>

#include "onux_gl/OpenGLData.hpp"

namespace onux_gl {
  using std::map;

  struct IImage;

  class Texture : public OpenGLData {
  public:
    typedef map<const GLenum, const GLint> Options;

  private:
    static const GLenum TARGET = GL_TEXTURE_2D;
    static const Options DEFAULT_OPTIONS;

    void loadImage(const IImage& image) const;
    void loadOptions(const Options& options) const;

  public:
    Texture(const IImage& image, const Options& options = DEFAULT_OPTIONS);
    ~Texture();

    void bind(const unsigned int unit) const;
  };
}
