#include "engine/GraphicsEngine.hpp"

#include <GL/glew.h>

#include "engine/Renderable.hpp"
#include "engine/MeshRenderer.hpp"
#include "graphics/Camera.hpp"

namespace onux {

struct GraphicsEngine::Impl {
    Drawables& drawables;
    Camera&    camera;

    void renderDrawables() const;
};

GraphicsEngine::GraphicsEngine(Drawables& drawables, Camera& camera)
    : impl(new Impl { drawables, camera }) {}

GraphicsEngine::~GraphicsEngine() {}

static void clearBuffers() {
    static const GLbitfield MASKS =
        GL_COLOR_BUFFER_BIT |
        GL_DEPTH_BUFFER_BIT;

    glClear(MASKS);
}

void GraphicsEngine::render() {
    clearBuffers();
    impl->renderDrawables();
}

// Implementation

void GraphicsEngine::Impl::renderDrawables() const {
    for (const Renderable* drawable : drawables) {
        drawable->enable(camera);
        drawable->getMeshRenderer().render();
    }
}

} // namespace onux
