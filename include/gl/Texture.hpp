#pragma once

#include <map>

#include "gl/OpenGLData.hpp"

namespace onux {

struct IImage;

class Texture : public OpenGLData {
public:
  typedef std::map<const GLenum, const GLint> Options;

  Texture(
    const IImage*  image,
    const Options& options = DEFAULT_OPTIONS
  );
  ~Texture();
  void bind(const unsigned int unit) const;

private:
  static const GLenum TARGET;
  static const Options DEFAULT_OPTIONS;

  void loadImage(const IImage* image) const;
  void loadOptions(const Options& options) const;
};

} // namespace onux
