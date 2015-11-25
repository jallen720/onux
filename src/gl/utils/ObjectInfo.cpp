#include "gl/utils/ObjectInfo.hpp"

#include <vector>

using std::string;
using std::vector;

namespace onux {

struct ObjectInfo::Impl {
    const GLuint   objectID;
    GetValueFunc   getValueFunc;
    GetInfoLogFunc getInfoLogFunc;

    Impl(
        const GLuint   objectID,
        GetValueFunc   getValueFunc,
        GetInfoLogFunc getInfoLogFunc
    );
};

ObjectInfo::ObjectInfo(
    const GLuint   objectID,
    GetValueFunc   getValueFunc,
    GetInfoLogFunc getInfoLogFunc
)   : impl(new Impl(objectID, getValueFunc, getInfoLogFunc)) {}

const GLint ObjectInfo::getValue(const GLenum parameter) const {
    GLint value;

    impl->getValueFunc(
        impl->objectID,
        parameter,
        &value
    );

    return value;
}

const string ObjectInfo::getInfoLog() const {
    vector<GLchar> infoLog(getValue(GL_INFO_LOG_LENGTH));

    impl->getInfoLogFunc(
        impl->objectID,
        infoLog.size(),
        nullptr,
        &infoLog[0]
    );

    return string(infoLog.begin(), infoLog.end());
}

// Implementation

ObjectInfo::Impl::Impl(
    const GLuint   objectID,
    GetValueFunc   getValueFunc,
    GetInfoLogFunc getInfoLogFunc
)   : objectID(objectID)
    , getValueFunc(getValueFunc)
    , getInfoLogFunc(getInfoLogFunc) {}

} // namespace onux
