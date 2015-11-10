#pragma once

#include <memory>
#include <glm/glm.hpp>

namespace onux {

class Transform;

class Camera {
public:
  Camera(const glm::mat4& projection);
  ~Camera();
  Transform& getTransform();
  const glm::mat4& getProjection() const;

private:
  struct Impl;
  std::unique_ptr<Impl> impl;
};

} // namespace onux
