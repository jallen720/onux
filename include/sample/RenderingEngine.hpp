#pragma once

#include <vector>

using std::vector;

class Renderable;
class Camera;

class RenderingEngine {
public:
  typedef vector<const Renderable*> Drawables;

private:
  const Drawables& drawables;
  Camera& camera;

public:
  RenderingEngine(const Drawables& drawables, Camera& camera);
  void clearBuffers() const;
  void render();
};
