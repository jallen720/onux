#include "engine/Renderable.hpp"

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "gl/Texture.hpp"
#include "gl/ShaderProgram.hpp"
#include "graphics/Mesh.hpp"
#include "graphics/Camera.hpp"
#include "graphics/Transform.hpp"
#include "engine/MeshRenderer.hpp"

using glm::mat4;

namespace onux {

struct Renderable::Impl {
  const Mesh&          mesh;
  const ShaderProgram& shaderProgram;
  Textures             textures;
  Transform            transform;
  const MeshRenderer   meshRenderer;

  Impl(
    const Mesh&          mesh,
    const ShaderProgram& shaderProgram,
    Textures             textures
  );
  void bindTextures() const;
  void setUniforms(
    const mat4& model,
    const mat4& view,
    const mat4& projection
  ) const;
};

Renderable::Renderable(
  const Mesh&          mesh,
  const ShaderProgram& shaderProgram,
  Textures             textures
) : impl(new Impl(mesh, shaderProgram, textures)) {}

void Renderable::enable(Camera& camera) const {
  impl->shaderProgram.use();
  impl->bindTextures();

  impl->setUniforms(
    impl->transform.getLocalMatrix(),
    camera.getTransform().getWorldMatrix(),
    camera.getProjection()
  );
}

const MeshRenderer& Renderable::getMeshRenderer() const {
  return impl->meshRenderer;
}

const ShaderProgram& Renderable::getShaderProgram() const {
  return impl->shaderProgram;
}

Transform& Renderable::getTransform() {
  return impl->transform;
}

// Implementation

Renderable::Impl::Impl(
  const Mesh&          mesh,
  const ShaderProgram& shaderProgram,
  Textures             textures
) : mesh(mesh)
  , shaderProgram(shaderProgram)
  , textures(textures)
  , meshRenderer(this->mesh) {}

void Renderable::Impl::bindTextures() const {
  for (auto i = 0u; i < textures.size(); i++) {
    textures[i]->bind(i);
  }
}

void Renderable::Impl::setUniforms(
  const mat4& model,
  const mat4& view,
  const mat4& projection
) const {
  shaderProgram.setUniform("model"     , model     );
  shaderProgram.setUniform("view"      , view      );
  shaderProgram.setUniform("projection", projection);
}

} // namespace onux
