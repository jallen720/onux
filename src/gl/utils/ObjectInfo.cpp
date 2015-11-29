#include "gl/utils/ObjectInfo.hpp"

#include <vector>

using std::string;
using std::vector;

namespace onux {

struct ObjectInfo::Impl {
    const GLuint objectID;
    GetValueFunc getValueFunc;
    GetLogFunc   getLogFunc;
};

ObjectInfo::ObjectInfo(
    const GLuint objectID,
    GetValueFunc getValueFunc,
    GetLogFunc   getLogFunc
)   : impl(new Impl({ objectID, getValueFunc, getLogFunc })) {}

ObjectInfo::~ObjectInfo() {}

const GLint ObjectInfo::getValue(const GLenum parameter) const {
    validateParameter(parameter);
    GLint value;

    impl->getValueFunc(
        impl->objectID,
        parameter,
        &value
    );

    return value;
}

const string ObjectInfo::getLog() const {
    vector<GLchar> log(getValue(GL_INFO_LOG_LENGTH));

    impl->getLogFunc(
        impl->objectID,
        log.size(),
        nullptr,
        &log[0]
    );

    return string(log.begin(), log.end());
}

} // namespace onux
