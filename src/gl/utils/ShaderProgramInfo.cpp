#include "gl/utils/ShaderProgramInfo.hpp"

#include "gl/utils/ValidValues.hpp"
#include "exceptions/argErrors/InvalidArg.hpp"

#include "MACROS/ONUX_STRINGIFY.hpp"

namespace onux {

void ShaderProgramInfo::validateParameter(const GLenum parameter) const {
    static const ValidValues VALID_SHADER_PROGRAM_PARAMETERS({
        ONUX_STRINGIFY(GL_DELETE_STATUS),
        ONUX_STRINGIFY(GL_LINK_STATUS),
        ONUX_STRINGIFY(GL_VALIDATE_STATUS),
        ONUX_STRINGIFY(GL_INFO_LOG_LENGTH),
        ONUX_STRINGIFY(GL_ATTACHED_SHADERS),
        ONUX_STRINGIFY(GL_ACTIVE_ATTRIBUTES),
        ONUX_STRINGIFY(GL_ACTIVE_ATTRIBUTE_MAX_LENGTH),
        ONUX_STRINGIFY(GL_ACTIVE_UNIFORMS),
        ONUX_STRINGIFY(GL_ACTIVE_UNIFORM_MAX_LENGTH),
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
