#pragma once

#include <functional>
#include <string>
#include <memory>
#include <GL/glew.h>

namespace onux {

class ObjectInfo {
private:
    typedef void (*GetValue)(const GLuint, const GLenum, GLint*);
    typedef void (*GetLog)(const GLuint, const GLsizei, GLsizei*, GLchar*);

public:
    ObjectInfo(
        const GLuint objectID,
        GetValue     getValue,
        GetLog       getLog
    );
    ~ObjectInfo();
    const GLint getValue(const GLenum parameter) const;
    const std::string getLog() const;

protected:
    virtual void validateParameter(const GLenum parameter) const = 0;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
