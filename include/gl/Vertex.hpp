#pragma once

#include <glm/glm.hpp>

namespace onux {

class Vertex {
public:
  Vertex();
  Vertex(
    const glm::vec3 position,
    const glm::vec3 normal,
    const glm::vec2 uv
  );
  static void definePointers();

private:
  const glm::vec3 m_position;
  const glm::vec3 m_normal;
  const glm::vec2 m_uv;
};

} // namespace onux
