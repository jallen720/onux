#pragma once

#include <memory>

#include "resources/containers/Resources.hpp"
#include "graphics/Model.hpp"

namespace onux {

class Models : public Resources<const Model> {
public:
    Models();
    ~Models();

protected:
    // Resources
    virtual Loader getLoader() const override;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
