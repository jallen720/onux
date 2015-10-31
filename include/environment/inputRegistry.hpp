#pragma once

struct GLFWwindow;

namespace onux {

struct IInput;

void registerInput(IInput* input, GLFWwindow* window);
void unregisterInput(const GLFWwindow*);

} // namespace onux
