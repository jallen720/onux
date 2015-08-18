#include "loggers.hpp"
#include "OpenGLData.hpp"
#include "Vertex.hpp"
#include "BufferObject.hpp"
#include "VertexBuffer.hpp"

struct IndexBuffer : BufferObject {
  IndexBuffer(
    const GLsizei dataSize,
    const GLuint* data,
    const GLenum  usage
  ) : BufferObject(GL_ELEMENT_ARRAY_BUFFER, dataSize, data, usage) {}
};

static GLuint newVertexArray() {
  GLuint id;
  glGenVertexArrays(1, &id);
  return id;
}

struct VertexArray : public OpenGLData {
  VertexArray(
    const VertexBuffer& vertexBuffer,
    const IndexBuffer&  indexBuffer
  ) : OpenGLData(newVertexArray()) {
    bind();
    vertexBuffer.loadData();
    indexBuffer.loadData();
    logCreation(this, "VertexArray");
  }

  ~VertexArray() {
    logDestruction(this, "VertexArray");
    glDeleteVertexArrays(1, &getID());
  }

  void bind() const {
    glBindVertexArray(getID());
  }
};

class Renderable {
  const VertexArray& vertexArray;
  const ShaderProgram& shaderProgram;

public:
  Renderable(
    const VertexArray& vertexArray,
    const ShaderProgram& shaderProgram
  ) : vertexArray(vertexArray)
    , shaderProgram(shaderProgram) {}

  void enable() const {
    vertexArray.bind();
    shaderProgram.use();
  }

  const ShaderProgram& getShaderProgram() const {
    return shaderProgram;
  }
};
