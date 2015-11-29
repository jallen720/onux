#pragma once

#include <memory>
#include <GL/glew.h>

namespace onux {

class GLData {
public:
    const GLuint& getID() const;

protected:
    explicit GLData(const GLuint id);
    ~GLData();

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
