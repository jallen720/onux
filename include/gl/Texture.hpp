#pragma once

#include <map>

#include "gl/OpenGLData.hpp"

namespace onux {

struct IImage;

class Texture : public OpenGLData {
public:
  typedef const std::map<const GLenum, const GLint> Options;

private:
  static const GLenum TARGET;
  static Options      DEFAULT_OPTIONS;

public:
  Texture(
    const IImage* image,
    Options&      options = DEFAULT_OPTIONS
  );
  ~Texture();
  void bind(const unsigned int unit) const;

private:
  void loadImage(const IImage* image) const;
  void loadOptions(Options& options) const;
};

} // namespace onux
