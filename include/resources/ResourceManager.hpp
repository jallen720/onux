#pragma once

#include <memory>
#include <string>

namespace onux {

class ShaderSources;
class Images;
class Scenes;

class ResourceManager {
private:
    static const std::string& DEFAULT_RESOURCES_DIRECTORY;

public:
    explicit ResourceManager(
        const std::string& resourcesDirectory = DEFAULT_RESOURCES_DIRECTORY
    );
    ~ResourceManager();
    const onux::ShaderSources& getShaderSources() const;
    const onux::Images& getImages() const;
    const onux::Scenes& getScenes() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
