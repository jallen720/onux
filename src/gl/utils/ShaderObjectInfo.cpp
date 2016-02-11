#include "gl/utils/ShaderObjectInfo.hpp"

#include "gl/utils/ValidValues.hpp"
#include "exceptions/argErrors/InvalidArg.hpp"

#include "MACROS/VALID_VALUE.hpp"

namespace onux {

void ShaderObjectInfo::validateParameter(const GLenum parameter) const {
    static const ValidValues VALID_SHADER_OBJECT_PARAMETERS({
        VALID_VALUE(GL_SHADER_TYPE),
        VALID_VALUE(GL_DELETE_STATUS),
        VALID_VALUE(GL_COMPILE_STATUS),
        VALID_VALUE(GL_INFO_LOG_LENGTH),
        VALID_VALUE(GL_SHADER_SOURCE_LENGTH),
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
