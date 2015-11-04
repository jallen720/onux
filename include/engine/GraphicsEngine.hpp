#pragma once

#include <vector>

namespace onux {

class Renderable;
class Camera;

class GraphicsEngine {
public:
  typedef const std::vector<const Renderable*> Drawables;

public:
  GraphicsEngine(Drawables& drawables, Camera& camera);
  void render();

private:
  Drawables& m_drawables;
  Camera&    m_camera;

  void renderDrawables() const;
};

} // namespace onux
