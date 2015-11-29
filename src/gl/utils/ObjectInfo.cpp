#include "gl/utils/ObjectInfo.hpp"

#include <vector>

using std::string;
using std::vector;

namespace onux {

struct ObjectInfo::Impl {
    const GLuint objectID;
    GetValue     getValue;
    GetLog       getLog;
};

ObjectInfo::ObjectInfo(
    const GLuint objectID,
    GetValue     getValue,
    GetLog       getLog
)   : impl(new Impl({ objectID, getValue, getLog })) {}

ObjectInfo::~ObjectInfo() {}

const GLint ObjectInfo::getValue(const GLenum parameter) const {
    validateParameter(parameter);
    GLint value;

    impl->getValue(
        impl->objectID,
        parameter,
        &value
    );

    return value;
}

const string ObjectInfo::getLog() const {
    vector<GLchar> log(getValue(GL_INFO_LOG_LENGTH));

    impl->getLog(
        impl->objectID,
        log.size(),
        nullptr,
        &log[0]
    );

    return string(log.begin(), log.end());
}

} // namespace onux
