#pragma once

#include <functional>
#include <string>
#include <memory>
#include <GL/glew.h>

namespace onux {

class ObjectInfo {
private:
  typedef void (*GetValueFunc)(GLuint, GLenum, GLint*);
  typedef void (*GetInfoLogFunc)(GLuint, GLsizei, GLsizei*, GLchar*);

public:
  ObjectInfo(
    const GLuint   objectID,
    GetValueFunc   getValueFunc,
    GetInfoLogFunc getInfoLogFunc
  );
  const GLint getValue(const GLenum parameter) const;
  const std::string getInfoLog() const;

private:
  struct Impl;
  std::shared_ptr<Impl> impl;
};

} // namespace onux
