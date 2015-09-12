#pragma once

class Window;
class GraphicsEngine;

class Engine {
public:
  Engine(const Window& window, GraphicsEngine& graphicsEngine);
  void run();

private:
  const Window&   m_window;
  GraphicsEngine& m_graphicsEngine;

  void renderObjects();
  void processFrame();
};
