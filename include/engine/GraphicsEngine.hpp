#pragma once

#include <memory>
#include <vector>

namespace onux {

class Renderable;
class Camera;

class GraphicsEngine {
public:
  typedef const std::vector<const Renderable*> Drawables;

public:
  GraphicsEngine(Drawables& drawables, Camera& camera);
  ~GraphicsEngine();
  void render();

private:
  struct Impl;
  std::unique_ptr<Impl> impl;
};

} // namespace onux
