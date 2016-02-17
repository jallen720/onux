#include "exceptions/subsystemErrors/GLFWError.hpp"

#include "exceptions/messageBuilders/buildSystemMessage.hpp"
#include "utils/toString.hpp"

using std::string;

namespace onux {

static const string buildGLFWMessage(const int code, const char* info) {
    return buildSystemMessage(
        "GLFW",
        "\n"
        "  code: " + toString(code) + "\n"
        "  info: " + info + "\n"
    );
}

GLFWError::GLFWError(const int code, const char* info)
    : Error(buildGLFWMessage(code, info)) {}

GLFWError::GLFWError(const string& message)
    : Error(buildSystemMessage("GLFW", message)) {}

} // namespace onux
