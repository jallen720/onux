#pragma once

#include <vector>

namespace onux {

class Renderable;
class Camera;

class GraphicsEngine {
public:
  typedef std::vector<const Renderable*> Drawables;

  GraphicsEngine(const Drawables& drawables, Camera& camera);
  void render();

private:
  const Drawables& m_drawables;
  Camera&          m_camera;

  void renderDrawables() const;
};

} // namespace onux
