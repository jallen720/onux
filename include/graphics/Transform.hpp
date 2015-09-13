#pragma once

#include <glm/glm.hpp>

namespace onux {

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
  const glm::mat4 getLocalMatrix() const;
  const glm::mat4 getWorldMatrix() const;

private:
  glm::vec3 m_position;
  glm::vec3 m_rotation;
  glm::vec3 m_scale;
};

} // namespace onux
