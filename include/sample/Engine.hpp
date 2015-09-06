#pragma once

class Window;
class Camera;
class RenderingEngine;

class Engine {
  const Window& window;
  Camera& camera;
  RenderingEngine& renderingEngine;

  void renderObjects();
  void processFrame();

public:
  Engine(
    const Window& window,
    Camera& camera,
    RenderingEngine& renderingEngine
  );

  void run();
};
