#pragma once

#include <glm/glm.hpp>

using glm::vec3;
using glm::mat4;

class Transform {
  vec3 position;
  vec3 rotation;
  vec3 m_scale;

protected:
  const virtual mat4 calculateMatrix(
    const vec3& position,
    const vec3& rotation,
    const vec3& scale
  ) const;

public:
  Transform();
  void translate(const vec3& translation);
  void rotate(const vec3& rotation);
  void scale(const vec3& scale);
  void setPosition(const vec3& position);
  void setRotation(const vec3& rotation);
  void setScale(const vec3& scale);
  const vec3& getPosition() const;
  const vec3& getRotation() const;
  const vec3& getScale() const;
  const mat4 getMatrix() const;
};
