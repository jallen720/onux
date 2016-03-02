#pragma once

#include <memory>

#include "MACROS/ONUX_PIMPL_COPY_DEFS.hpp"

namespace onux {

class Model;
class Camera;
class Transform;

class Entity {
public:
    explicit Entity(const Model* model);
    ONUX_PIMPL_COPY_DEFS(Entity)
    void enable(Camera& camera) const;
    const Model* getModel() const;
    Transform& getTransform();
    const Transform& getTransform() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
