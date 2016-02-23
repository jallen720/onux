#pragma once

#include <memory>

namespace onux {

class ResourceManager;
class Shaders;
class Textures;

class AssetManager {
public:
    explicit AssetManager(const ResourceManager& resourceManager);
    ~AssetManager();
    const Shaders& getShaders() const;
    const Textures& getTextures() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
