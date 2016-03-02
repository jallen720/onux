#pragma once

#include <memory>
#include <vector>

namespace onux {

class Entity;
class Camera;

class GraphicsEngine {
public:
    using Entities = std::vector<Entity>;

public:
    GraphicsEngine(const Entities& entities, Camera& camera);
    ~GraphicsEngine();
    void render();

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
