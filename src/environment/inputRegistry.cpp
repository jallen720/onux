#include "environment/inputRegistry.hpp"

#include <map>
#include <string>
#include <GLFW/glfw3.h>

#include "exceptions/validators/validateNotNull.hpp"
#include "environment/interfaces/IInput.hpp"
#include "utils/contains.hpp"

using std::map;
using std::string;

namespace onux {

static map<const GLFWwindow*, IInput*> inputs;

static const bool hasInput(const GLFWwindow* window) {
    return contains(inputs, window);
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
    validateNotNull("input", "registerInput", input);
    validateNotNull("window", "registerInput", window);
    inputs[window] = input;
    glfwSetCursorPosCallback(window, cursorPosCallback);
}

void unregisterInput(const GLFWwindow* window) {
    validateNotNull("window", "unregisterInput", window);
    inputs.erase(window);
}

} // namespace onux
