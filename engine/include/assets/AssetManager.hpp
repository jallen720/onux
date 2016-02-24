#pragma once

#include <memory>

#include "utils/UniqueMap.hpp"

namespace onux {

class ResourceManager;
class ShaderProgram;
class Texture;

class AssetManager {
public:
    explicit AssetManager(const ResourceManager& resourceManager);
    ~AssetManager();
    const UniqueMap<ShaderProgram>& getShaderPrograms() const;
    const UniqueMap<Texture>& getTextures() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
