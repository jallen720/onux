#pragma once

#include <vector>

class Renderable;
class Camera;

class GraphicsEngine {
public:
  typedef std::vector<const Renderable*> Drawables;

  GraphicsEngine(const Drawables& drawables, Camera& camera);
  void clearBuffers() const;
  void render();

private:
  const Drawables& drawables;
  Camera& camera;
};
