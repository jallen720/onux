#include "sample/Renderable.hpp"

#include <GL/glew.h>

#include "Camera.hpp"

void Renderable::bindTextures() const {
  for (auto i = 0u; i < textures.size(); i++)
    textures[i]->bind(i);
}

void Renderable::setUniforms(
  const mat4& model,
  const mat4& view,
  const mat4& projection
) const {
  shaderProgram.setUniform("model"     , model     , GL_FALSE);
  shaderProgram.setUniform("view"      , view      , GL_FALSE);
  shaderProgram.setUniform("projection", projection, GL_FALSE);
}

Renderable::Renderable(
  const Mesh* mesh,
  const ShaderProgram& shaderProgram,
  Textures textures
) : mesh(mesh)
  , shaderProgram(shaderProgram)
  , textures(textures) {}

void Renderable::enable(Camera& camera) const {
  mesh->use();
  shaderProgram.use();

  setUniforms(
    transform.getMatrix(),
    camera.getViewTransform().getMatrix(),
    camera.getProjection()
  );

  bindTextures();
}

const ShaderProgram& Renderable::getShaderProgram() const {
  return shaderProgram;
}

Transform& Renderable::getTransform() {
  return transform;
}
