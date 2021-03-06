#include "gl/utils/ShaderProgramInfo.hpp"

#include "utils/ValidGLValues.hpp"
#include "exceptions/argErrors/InvalidArg.hpp"

#include "MACROS/ONUX_VALID_GL_VALUE.hpp"

namespace onux {

void ShaderProgramInfo::validateParameter(const GLenum parameter) const {
    static const ValidGLValues VALID_SHADER_PROGRAM_PARAMETERS({
        ONUX_VALID_GL_VALUE(GL_DELETE_STATUS),
        ONUX_VALID_GL_VALUE(GL_LINK_STATUS),
        ONUX_VALID_GL_VALUE(GL_VALIDATE_STATUS),
        ONUX_VALID_GL_VALUE(GL_INFO_LOG_LENGTH),
        ONUX_VALID_GL_VALUE(GL_ATTACHED_SHADERS),
        ONUX_VALID_GL_VALUE(GL_ACTIVE_ATTRIBUTES),
        ONUX_VALID_GL_VALUE(GL_ACTIVE_ATTRIBUTE_MAX_LENGTH),
        ONUX_VALID_GL_VALUE(GL_ACTIVE_UNIFORMS),
        ONUX_VALID_GL_VALUE(GL_ACTIVE_UNIFORM_MAX_LENGTH),
    });

    if (!VALID_SHADER_PROGRAM_PARAMETERS.contains(parameter)) {
        throw InvalidArg(
            "parameter",
            "ShaderProgramInfo::getValue",
            VALID_SHADER_PROGRAM_PARAMETERS.getNames()
        );
    }
}

} // namespace onux
