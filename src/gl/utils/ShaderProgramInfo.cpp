#include "gl/utils/ShaderProgramInfo.hpp"

#include "gl/utils/ValidValues.hpp"
#include "exceptions/argErrors/InvalidArg.hpp"

#include "MACROS/VALID_VALUE.hpp"

namespace onux {

void ShaderProgramInfo::validateParameter(const GLenum parameter) const {
    static const ValidValues VALID_SHADER_PROGRAM_PARAMETERS({
        VALID_VALUE(GL_DELETE_STATUS),
        VALID_VALUE(GL_LINK_STATUS),
        VALID_VALUE(GL_VALIDATE_STATUS),
        VALID_VALUE(GL_INFO_LOG_LENGTH),
        VALID_VALUE(GL_ATTACHED_SHADERS),
        VALID_VALUE(GL_ACTIVE_ATTRIBUTES),
        VALID_VALUE(GL_ACTIVE_ATTRIBUTE_MAX_LENGTH),
        VALID_VALUE(GL_ACTIVE_UNIFORMS),
        VALID_VALUE(GL_ACTIVE_UNIFORM_MAX_LENGTH),
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
