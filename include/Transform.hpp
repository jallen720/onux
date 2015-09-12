#pragma once

#include <glm/glm.hpp>

class Transform {
public:
  Transform();
  void translate(const glm::vec3& translation);
  void rotate(const glm::vec3& rotation);
  void scale(const glm::vec3& scale);
  void setPosition(const glm::vec3& position);
  void setRotation(const glm::vec3& rotation);
  void setScale(const glm::vec3& scale);
  const glm::vec3& getPosition() const;
  const glm::vec3& getRotation() const;
  const glm::vec3& getScale() const;
  const glm::mat4 getMatrix() const;

protected:
  const virtual glm::mat4 calculateMatrix(
    const glm::vec3& position,
    const glm::vec3& rotation,
    const glm::vec3& scale
  ) const;

private:
  glm::vec3 m_position;
  glm::vec3 m_rotation;
  glm::vec3 m_scale;
};
