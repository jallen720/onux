#pragma once

#include <vector>
#include <glm/glm.hpp>

#include "Transform.hpp"
#include "onux_gl/Texture.hpp"
#include "onux_gl/ShaderProgram.hpp"
#include "onux_gl/VertexArray.hpp"

using std::vector;
using glm::mat4;
using onux_gl::Texture;
using onux_gl::ShaderProgram;
using onux_gl::VertexArray;

class Camera;

class Renderable {
public:
  typedef const vector<const Texture*> Textures;

private:
  const VertexArray& vertexArray;
  const ShaderProgram& shaderProgram;
  Textures textures;
  Transform transform;

  void bindTextures() const;

  void setUniforms(
    const mat4& model,
    const mat4& view,
    const mat4& projection
  ) const;

public:
  Renderable(
    const VertexArray& vertexArray,
    const ShaderProgram& shaderProgram,
    Textures textures
  );

  void enable(Camera& camera) const;
  const ShaderProgram& getShaderProgram() const;
  Transform& getTransform();
};
