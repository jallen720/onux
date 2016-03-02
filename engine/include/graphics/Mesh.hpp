#pragma once

#include <memory>
#include <vector>

namespace onux {

class Texture;
class VertexData;
class VertexArray;
class ShaderProgram;

class Mesh {
public:
    using Ptr      = std::unique_ptr<const Mesh>;
    using Textures = std::vector<const Texture*>;

public:
    static Ptr create(
        const VertexData&    vertexData,
        Textures             textures,
        const ShaderProgram* shaderProgram
    );

public:
    ~Mesh();
    const VertexArray& getVertexArray() const;
    const ShaderProgram* getShaderProgram() const;
    void setAsRenderTarget() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;

    Mesh(
        const VertexData&    vertexData,
        Textures&            textures,
        const ShaderProgram* shaderProgram
    );
};

} // namespace onux
