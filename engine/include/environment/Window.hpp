#pragma once

#include <memory>

struct GLFWwindow;

namespace onux {

class Input;

class Window {
public:
    Window(
        const unsigned int width,
        const unsigned int height,
        const char*        name
    );
    ~Window();
    void makeContextCurrent() const;
    const float getAspectRatio() const;
    const bool shouldClose() const;
    void swapBuffers() const;
    Input& getInput();

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
