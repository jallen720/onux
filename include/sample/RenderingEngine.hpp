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

public:
  RenderingEngine(const Drawables& drawables);
  void clearBuffers() const;
  void render(Camera& camera);
};
