#pragma once

#include <memory>
#include <vector>

namespace onux {

class Texture;
class Mesh;
class ShaderProgram;
class Camera;
class MeshRenderer;
class Transform;

class Renderable {
public:
    using Textures = const std::vector<const Texture*>;

public:
    Renderable(
        const Mesh*          mesh,
        const ShaderProgram* shaderProgram,
        Textures             textures
    );
    void enable(Camera& camera) const;
    const MeshRenderer& getMeshRenderer() const;
    Transform& getTransform();

private:
    struct Impl;
    std::shared_ptr<Impl> impl;
};

} // namespace onux
