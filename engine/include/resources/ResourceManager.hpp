#pragma once

#include <memory>
#include <string>

#include "resources/Resources.hpp"
#include "resources/files/ShaderFile.hpp"
#include "graphics/ShaderSource.hpp"
#include "graphics/Image.hpp"
#include "graphics/Model.hpp"

namespace onux {

class ResourceManager {
public:
    explicit ResourceManager(const std::string& resourcesDirectory);
    ~ResourceManager();
    const Resources<ShaderFile>& getShaderFiles() const;
    const Resources<ShaderSource>& getShaderSources() const;
    const Resources<Image>& getImages() const;
    const Resources<Model>& getModels() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
