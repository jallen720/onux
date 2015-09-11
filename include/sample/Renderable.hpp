#pragma once

#include <vector>
#include <glm/glm.hpp>

#include "Transform.hpp"
#include "onux_gl/Texture.hpp"
#include "onux_gl/ShaderProgram.hpp"
#include "sample/MeshRenderer.hpp"

class Mesh;
class Camera;

class Renderable {
public:
  typedef std::vector<const onux_gl::Texture*> Textures;

  Renderable(
    const Mesh& mesh,
    const onux_gl::ShaderProgram& shaderProgram,
    const Textures textures
  );
  void enable(Camera& camera) const;
  const MeshRenderer& getMeshRenderer() const;
  const onux_gl::ShaderProgram& getShaderProgram() const;
  Transform& getTransform();

private:
  const Mesh&                   m_mesh;
  const onux_gl::ShaderProgram& m_shaderProgram;
  const Textures                m_textures;
  Transform                     m_transform;
  const MeshRenderer            m_meshRenderer;

  void bindTextures() const;
  void setUniforms(
    const glm::mat4& model,
    const glm::mat4& view,
    const glm::mat4& projection
  ) const;
};
