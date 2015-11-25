#include "gl/utils/getErrorMessage.hpp"

#include <map>

using std::string;
using std::map;

namespace onux {

const string& getErrorMessage(const GLenum error) {
    static const map<const GLenum, const string> ERROR_MESSAGES {
        { GL_NO_ERROR                      , "No error"                      },
        { GL_INVALID_ENUM                  , "Invalid enum"                  },
        { GL_INVALID_VALUE                 , "Invalid value"                 },
        { GL_INVALID_OPERATION             , "Invalid operation"             },
        { GL_INVALID_FRAMEBUFFER_OPERATION , "Invalid framebuffer operation" },
        { GL_OUT_OF_MEMORY                 , "Out of memory"                 },
        { GL_STACK_UNDERFLOW               , "Stack underflow"               },
        { GL_STACK_OVERFLOW                , "Stack overflow"                },
    };

    return ERROR_MESSAGES.at(error);
}

} // namespace onux
