#pragma once

class Window;
class GraphicsEngine;

class Engine {
  const Window& window;
  GraphicsEngine& graphicsEngine;

  void renderObjects();
  void processFrame();

public:
  Engine(const Window& window, GraphicsEngine& graphicsEngine);

  void run();
};
