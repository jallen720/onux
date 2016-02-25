#pragma once

#include <memory>
#include <string>

#include "utils/UniqueMap.hpp"

namespace onux {

class Shader;
class ShaderSource;
class Image;
class Model;

class ResourceManager {
public:
    explicit ResourceManager(const std::string& resourcesDirectory);
    ~ResourceManager();
    const UniqueMap<Shader>& getShaders() const;
    const UniqueMap<ShaderSource>& getShaderSources() const;
    const UniqueMap<Image>& getImages() const;
    const UniqueMap<Model>& getModels() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
