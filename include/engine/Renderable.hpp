#pragma once

#include <vector>
#include <glm/glm.hpp>

#include "graphics/Transform.hpp"
#include "engine/MeshRenderer.hpp"

namespace onux {

class Texture;
class Mesh;
class ShaderProgram;
class Camera;

class Renderable {
public:
  typedef const std::vector<const Texture*> Textures;

public:
  Renderable(
    const Mesh&          mesh,
    const ShaderProgram& shaderProgram,
    Textures             textures
  );
  void enable(Camera& camera) const;
  const MeshRenderer& getMeshRenderer() const;
  const ShaderProgram& getShaderProgram() const;
  Transform& getTransform();

private:
  const Mesh&          m_mesh;
  const ShaderProgram& m_shaderProgram;
  Textures             m_textures;
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
