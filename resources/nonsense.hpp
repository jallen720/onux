#include "loggers.hpp"
#include "OpenGLData.hpp"
#include "Vertex.hpp"

static GLuint newBuffer() {
  GLuint id;
  glGenBuffers(1, &id);
  return id;
}

class BufferObject : public OpenGLData {
  const GLenum  target;
  const GLsizei dataSize;
  const GLvoid* data;
  const GLenum  usage;

protected:
  BufferObject(
    const GLenum  target,
    const GLsizei dataSize,
    const GLvoid* data,
    const GLenum  usage
  ) : OpenGLData(newBuffer())
    , target(target)
    , dataSize(dataSize)
    , data(data)
    , usage(usage) {
    logCreation(this, "BufferObject");
  }

  void bind() const {
    glBindBuffer(target, getID());
  }

public:
  ~BufferObject() {
    logDestruction(this, "BufferObject");
    glDeleteBuffers(1, &getID());
  }

  virtual void loadData() const {
    bind();
    glBufferData(target, dataSize, data, usage);
  }
};

struct VertexBufferObject : BufferObject {
  VertexBufferObject(
    const GLsizei dataSize,
    const GLvoid* data,
    const GLenum  usage
  ) : BufferObject(GL_ARRAY_BUFFER, dataSize, data, usage) {}

  void loadData() const override {
    BufferObject::loadData();
    Vertex::attributePointers();
  }
};

struct IndexBufferObject : BufferObject {
  IndexBufferObject(
    const GLsizei dataSize,
    const GLvoid* data,
    const GLenum  usage
  ) : BufferObject(GL_ELEMENT_ARRAY_BUFFER, dataSize, data, usage) {}
};

static GLuint newVertexArray() {
  GLuint id;
  glGenVertexArrays(1, &id);
  return id;
}

struct VertexArrayObject : public OpenGLData {
  VertexArrayObject(
    const VertexBufferObject& vertexBufferObject,
    const IndexBufferObject&  indexBufferObject
  ) : OpenGLData(newVertexArray()) {
    bind();
    vertexBufferObject.loadData();
    indexBufferObject.loadData();
    logCreation(this, "VertexArrayObject");
  }

  ~VertexArrayObject() {
    logDestruction(this, "VertexArrayObject");
    glDeleteVertexArrays(1, &getID());
  }

  void bind() const {
    glBindVertexArray(getID());
  }
};

class Renderable {
  const VertexArrayObject& vertexArray;
  const ShaderProgram& shaderProgram;

public:
  Renderable(
    const VertexArrayObject& vertexArray,
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
