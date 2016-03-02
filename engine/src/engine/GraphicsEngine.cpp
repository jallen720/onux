#include "engine/GraphicsEngine.hpp"

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "engine/Entity.hpp"
#include "graphics/Camera.hpp"
#include "graphics/Mesh.hpp"
#include "graphics/Transform.hpp"
#include "gl/VertexArray.hpp"
#include "gl/Texture.hpp"
#include "gl/ShaderProgram.hpp"
#include "assets/Model.hpp"

using glm::mat4;

namespace onux {

struct GraphicsEngine::Impl {
    const Entities& entities;
    Camera&         camera;

    void renderEntities() const;
};

GraphicsEngine::GraphicsEngine(const Entities& entities, Camera& camera)
    : impl(new Impl { entities, camera }) {}

GraphicsEngine::~GraphicsEngine() {}

static void clearBuffers() {
    static const GLbitfield MASKS =
        GL_COLOR_BUFFER_BIT |
        GL_DEPTH_BUFFER_BIT;

    glClear(MASKS);
}

void GraphicsEngine::render() {
    clearBuffers();
    impl->renderEntities();
}

// Implementation

static void drawElements(const GLsizei indexCount) {
    static const GLenum  MODE  = GL_TRIANGLES;
    static const GLenum  TYPE  = GL_UNSIGNED_INT;
    static const GLvoid* FIRST = 0;
    glDrawElements(MODE, indexCount, TYPE, FIRST);
}

static void setUniforms(
    const ShaderProgram* shaderProgram,
    const mat4&          model,
    const mat4&          view,
    const mat4&          projection
) {
    shaderProgram->setUniform("model"     , model     );
    shaderProgram->setUniform("view"      , view      );
    shaderProgram->setUniform("projection", projection);
}

void GraphicsEngine::Impl::renderEntities() const {
    for (const Entity& entity : entities) {
        entity.getModel()->forEachMesh([&](const Mesh* mesh) {
            mesh->setAsRenderTarget();

            setUniforms(
                mesh->getShaderProgram(),
                entity.getTransform().getLocalMatrix(),
                camera.getTransform().getLocalMatrix(),
                camera.getProjection()
            );

            drawElements(mesh->getVertexArray().getIndexCount());
        });
    }
}

} // namespace onux
