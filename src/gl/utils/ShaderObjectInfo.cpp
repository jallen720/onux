#include "gl/utils/ShaderObjectInfo.hpp"

#include "utils/ValidGLValues.hpp"
#include "exceptions/argErrors/InvalidArg.hpp"

#include "MACROS/ONUX_VALID_GL_VALUE.hpp"

namespace onux {

void ShaderObjectInfo::validateParameter(const GLenum parameter) const {
    static const ValidGLValues VALID_SHADER_OBJECT_PARAMETERS({
        ONUX_VALID_GL_VALUE(GL_SHADER_TYPE),
        ONUX_VALID_GL_VALUE(GL_DELETE_STATUS),
        ONUX_VALID_GL_VALUE(GL_COMPILE_STATUS),
        ONUX_VALID_GL_VALUE(GL_INFO_LOG_LENGTH),
        ONUX_VALID_GL_VALUE(GL_SHADER_SOURCE_LENGTH),
    });

    if (!VALID_SHADER_OBJECT_PARAMETERS.contains(parameter)) {
        throw InvalidArg(
            "parameter",
            "ShaderObjectInfo::getValue",
            VALID_SHADER_OBJECT_PARAMETERS.getNames()
        );
    }
}

} // namespace onux
