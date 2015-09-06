#pragma once

class Window;
class RenderingEngine;

class Engine {
  const Window& window;
  RenderingEngine& renderingEngine;

  void renderObjects();
  void processFrame();

public:
  Engine(const Window& window, RenderingEngine& renderingEngine);

  void run();
};
