#include "environment/Window.hpp"

#include <string>
#include <GLFW/glfw3.h>

#include "environment/Input.hpp"
#include "exceptions/argErrors/InvalidArg.hpp"
#include "exceptions/validators/validateNotNull.hpp"
#include "exceptions/validators/validateNotEmpty.hpp"
#include "utils/toString.hpp"

using std::string;

namespace onux {

struct Window::Impl {
    GLFWwindow*  glfwWindow;
    Input        input;
    unsigned int width;
    unsigned int height;

    Impl(
        const unsigned int width,
        const unsigned int height,
        const char*        name
    );
};

static void validateDimension(
    const unsigned int dimension,
    const string&      dimensionName
) {
    static const auto MIN_DIMENSION_SIZE = 1u;

    if (dimension < MIN_DIMENSION_SIZE) {
        throw InvalidArg(
            dimensionName,
            "Window::Window",
            ">= " + toString(MIN_DIMENSION_SIZE)
        );
    }
}

static const unsigned int getValidDimension(
    const unsigned int dimension,
    const string&      dimensionName
) {
    validateDimension(dimension, dimensionName);
    return dimension;
}

static const char* getValidName(const char* name) {
    validateNotNull("name", "Window::Window", name);
    validateNotEmpty("name", "Window::Window", name);
    return name;
}

Window::Window(
    const unsigned int width,
    const unsigned int height,
    const char*        name
)   : impl(new Impl(
        getValidDimension(width, "width"),
        getValidDimension(height, "height"),
        getValidName(name)
    )) {}

Window::~Window() {
    glfwDestroyWindow(impl->glfwWindow);
}

void Window::makeContextCurrent() const {
    glfwMakeContextCurrent(impl->glfwWindow);
}

const float Window::getAspectRatio() const {
    return (float)impl->width / impl->height;
}

const bool Window::shouldClose() const {
    return glfwWindowShouldClose(impl->glfwWindow);
}

void Window::swapBuffers() const {
    glfwSwapBuffers(impl->glfwWindow);
}

Input& Window::getInput() {
    return impl->input;
}

// Implementation

Window::Impl::Impl(
    const unsigned int width,
    const unsigned int height,
    const char*        name
)   : glfwWindow(glfwCreateWindow(
        width,
        height,
        name,
        nullptr,
        nullptr
    ))
    , input(glfwWindow)
    , width(width)
    , height(height) {}

} // namespace onux
