#pragma once

#include <vector>
#include <glm/glm.hpp>

#include "Transform.hpp"
#include "sample/MeshRenderer.hpp"

namespace onux {

class Texture;
class Mesh;
class ShaderProgram;
class Camera;

class Renderable {
public:
  typedef std::vector<const Texture*> Textures;

  Renderable(
    const Mesh&          mesh,
    const ShaderProgram& shaderProgram,
    const Textures       textures
  );
  void enable(Camera& camera) const;
  const MeshRenderer& getMeshRenderer() const;
  const ShaderProgram& getShaderProgram() const;
  Transform& getTransform();

private:
  const Mesh&          m_mesh;
  const ShaderProgram& m_shaderProgram;
  const Textures       m_textures;
  Transform            m_transform;
  const MeshRenderer   m_meshRenderer;

  void bindTextures() const;
  void setUniforms(
    const glm::mat4& model,
    const glm::mat4& view,
    const glm::mat4& projection
  ) const;
};

} // namespace onux
