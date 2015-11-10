#pragma once

#include <memory>
#include <map>

#include "gl/OpenGLData.hpp"

namespace onux {

struct IImage;

class Texture : public OpenGLData {
public:
  typedef const std::map<const GLenum, const GLint> Options;

private:
  static Options DEFAULT_OPTIONS;

public:
  Texture(
    const IImage* image,
    Options&      options = DEFAULT_OPTIONS
  );
  ~Texture();
  void bind(const GLuint unit) const;

private:
  struct Impl;
  std::unique_ptr<Impl> impl;
};

} // namespace onux
