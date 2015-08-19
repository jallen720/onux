#pragma once

#include <map>

#include "OpenGLData.hpp"

using std::map;

class Image;

class Texture : OpenGLData {
public:
  typedef map<const GLenum, const GLint> Options;

private:
  static const GLenum TARGET = GL_TEXTURE_2D;
  static const Options DEFAULT_OPTIONS;

  void loadImage(const Image& image) const;
  void loadOptions(const Options& options) const;

public:
  Texture(const Image& image, const Options& options = DEFAULT_OPTIONS);
  ~Texture();

  void bind(const unsigned int unit) const;
};
