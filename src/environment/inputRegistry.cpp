#include "environment/inputRegistry.hpp"

#include <map>
#include <string>
#include <GLFW/glfw3.h>

#include "exceptions/argErrors/NullArg.hpp"
#include "environment/interfaces/IInput.hpp"

using std::map;
using std::string;

namespace onux {

static map<const GLFWwindow*, IInput*> inputs;

static void validateInput(const IInput* input) {
    if (input == nullptr) {
        throw NullArg("input", "registerInput");
    }
}

static void validateWindow(const string& functionName, const GLFWwindow* window) {
    if (window == nullptr) {
        throw NullArg("window", functionName);
    }
}

static const bool hasInput(const GLFWwindow* window) {
    return inputs.count(window) != 0;
}

static void cursorPosCallback(
    GLFWwindow*  window,
    const double x,
    const double y
) {
    if (hasInput(window)) {
        inputs[window]->cursorPosEvent(x, y);
    }
}

void registerInput(IInput* input, GLFWwindow* window) {
    validateInput(input);
    validateWindow("registerInput", window);
    inputs[window] = input;
    glfwSetCursorPosCallback(window, cursorPosCallback);
}

void unregisterInput(const GLFWwindow* window) {
    validateWindow("unregisterInput", window);
    inputs.erase(window);
}

} // namespace onux
