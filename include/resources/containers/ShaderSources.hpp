#pragma once

#include <memory>

#include "resources/containers/Resources.hpp"
#include "graphics/ShaderSource.hpp"

namespace onux {

class ShaderSources : public Resources<const ShaderSource> {
public:
    ShaderSources();
    ~ShaderSources();

protected:
    // Resources
    virtual Loader getLoader() const override;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
