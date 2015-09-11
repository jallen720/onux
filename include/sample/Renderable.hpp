#pragma once

#include <vector>
#include <glm/glm.hpp>

#include "Transform.hpp"
#include "onux_gl/Texture.hpp"
#include "onux_gl/ShaderProgram.hpp"
#include "Mesh.hpp"

class Camera;

class Renderable {
public:
  typedef std::vector<const onux_gl::Texture*> Textures;

  Renderable(
    const Mesh* mesh,
    const onux_gl::ShaderProgram& shaderProgram,
    const Textures textures
  );
  void enable(Camera& camera) const;
  const Mesh* getMesh() const;
  const onux_gl::ShaderProgram& getShaderProgram() const;
  Transform& getTransform();

private:
  const Mesh* mesh;
  const onux_gl::ShaderProgram& shaderProgram;
  const Textures textures;
  Transform transform;

  void bindTextures() const;
  void setUniforms(
    const glm::mat4& model,
    const glm::mat4& view,
    const glm::mat4& projection
  ) const;
};
