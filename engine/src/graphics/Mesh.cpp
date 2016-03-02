#include "graphics/Mesh.hpp"

#include "graphics/VertexData.hpp"
#include "gl/Texture.hpp"
#include "gl/VertexArray.hpp"
#include "gl/ShaderProgram.hpp"
#include "exceptions/validators/validateNotNull.hpp"

namespace onux {

struct Mesh::Impl {
    const VertexArray    vertexArray;
    const Textures       textures;
    const ShaderProgram* shaderProgram;

    Impl(
        const VertexData&    vertexData,
        Textures&            textures,
        const ShaderProgram* shaderProgram
    );
    void bindTextures() const;
};

auto Mesh::create(
    const VertexData&    vertexData,
    Textures             textures,
    const ShaderProgram* shaderProgram
) -> Ptr {
    validateNotNull("shaderProgram", "Mesh::create", shaderProgram);
    return Ptr(new Mesh(vertexData, textures, shaderProgram));
}

Mesh::Mesh(
    const VertexData&    vertexData,
    Textures&            textures,
    const ShaderProgram* shaderProgram
)   : impl(new Impl(
        vertexData,
        textures,
        shaderProgram
    )) {}

Mesh::~Mesh() {}

const VertexArray& Mesh::getVertexArray() const {
    return impl->vertexArray;
}

const ShaderProgram* Mesh::getShaderProgram() const {
    return impl->shaderProgram;
}

void Mesh::setAsRenderTarget() const {
    impl->bindTextures();
    impl->vertexArray.bind();
    impl->shaderProgram->use();
}

// Implementation

Mesh::Impl::Impl(
    const VertexData&    vertexData,
    Textures&            textures,
    const ShaderProgram* shaderProgram
)   : vertexArray(vertexData)
    , textures(textures)
    , shaderProgram(shaderProgram) {}

void Mesh::Impl::bindTextures() const {
    for (auto i = 0u; i < textures.size(); i++) {
        textures[i]->bind(i);
    }
}

} // namespace onux
