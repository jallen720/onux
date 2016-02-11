#include "gl/utils/ShaderObjectInfo.hpp"

#include "gl/utils/ValidValues.hpp"
#include "exceptions/argErrors/InvalidArg.hpp"

#include "MACROS/ONUX_STRINGIFY.hpp"

namespace onux {

void ShaderObjectInfo::validateParameter(const GLenum parameter) const {
    static const ValidValues VALID_SHADER_OBJECT_PARAMETERS({
        ONUX_STRINGIFY(GL_SHADER_TYPE),
        ONUX_STRINGIFY(GL_DELETE_STATUS),
        ONUX_STRINGIFY(GL_COMPILE_STATUS),
        ONUX_STRINGIFY(GL_INFO_LOG_LENGTH),
        ONUX_STRINGIFY(GL_SHADER_SOURCE_LENGTH),
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
