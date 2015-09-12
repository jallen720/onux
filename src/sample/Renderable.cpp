#include "sample/Renderable.hpp"

#include <GL/glew.h>

#include "gl/Texture.hpp"
#include "gl/ShaderProgram.hpp"
#include "Mesh.hpp"
#include "Camera.hpp"

using glm::mat4;

namespace onux {

Renderable::Renderable(
  const Mesh&          mesh,
  const ShaderProgram& shaderProgram,
  const Textures       textures
) : m_mesh(mesh)
  , m_shaderProgram(shaderProgram)
  , m_textures(textures)
  , m_meshRenderer(m_mesh) {}

void Renderable::enable(Camera& camera) const {
  m_shaderProgram.use();
  bindTextures();

  setUniforms(
    m_transform.getMatrix(),
    camera.getViewTransform().getMatrix(),
    camera.getProjection()
  );
}

const MeshRenderer& Renderable::getMeshRenderer() const {
  return m_meshRenderer;
}

const ShaderProgram& Renderable::getShaderProgram() const {
  return m_shaderProgram;
}

Transform& Renderable::getTransform() {
  return m_transform;
}

void Renderable::bindTextures() const {
  for (auto i = 0u; i < m_textures.size(); i++) {
    m_textures[i]->bind(i);
  }
}

void Renderable::setUniforms(
  const mat4& model,
  const mat4& view,
  const mat4& projection
) const {
  m_shaderProgram.setUniform("model", model);
  m_shaderProgram.setUniform("view", view);
  m_shaderProgram.setUniform("projection", projection);
}

} // namespace onux
