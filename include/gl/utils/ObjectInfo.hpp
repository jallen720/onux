#pragma once

#include <functional>
#include <string>
#include <memory>
#include <GL/glew.h>

namespace onux {

class ObjectInfo {
private:
    typedef void (*GetValueFunc)(GLuint, GLenum, GLint*);
    typedef void (*GetLogFunc)(GLuint, GLsizei, GLsizei*, GLchar*);

public:
    ObjectInfo(
        const GLuint objectID,
        GetValueFunc getValueFunc,
        GetLogFunc   getLogFunc
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
