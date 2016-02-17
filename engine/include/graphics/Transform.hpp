#pragma once

#include <memory>
#include <glm/glm.hpp>

namespace onux {

class Transform {
public:
    Transform();
    ~Transform();
    void translate(const glm::vec3& translation);
    void rotate(const glm::vec3& rotation);
    void scale(const glm::vec3& scale);
    void setPosition(const glm::vec3& position);
    void setRotation(const glm::vec3& rotation);
    void setScale(const glm::vec3& scale);
    const glm::vec3& getPosition() const;
    const glm::vec3& getRotation() const;
    const glm::vec3& getScale() const;
    const glm::mat4 getLocalMatrix() const;
    const glm::mat4 getWorldMatrix() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
