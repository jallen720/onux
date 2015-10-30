#pragma once

struct GLFWwindow;

namespace onux {

struct IInput;

void registerInput(GLFWwindow* window, IInput* input);
void unregisterInput(const GLFWwindow*);

} // namespace onux
