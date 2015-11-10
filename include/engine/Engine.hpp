#pragma once

#include <memory>

namespace onux {

class Window;
class GraphicsEngine;

class Engine {
public:
  Engine(const Window& window, GraphicsEngine& graphicsEngine);
  ~Engine();
  void run();

private:
  struct Impl;
  std::unique_ptr<Impl> impl;
};

} // namespace onux
