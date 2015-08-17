#include <iostream>
#include <stdexcept>
#include <glm/glm.hpp>

#include "loggers.hpp"
#include "OpenGLData.hpp"

using std::cout;
using std::runtime_error;
using glm::vec4;

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

static size_t typeSize(const GLenum type) {
  switch (type) {
    case GL_FLOAT:
      return sizeof(GLfloat);
    default:
      throw runtime_error("Failed to get size for GL type!");
  }
}

class VertexAttribute {
  const GLchar*   name;
  const GLint     count;
  const GLenum    type;
  const GLboolean norm;
  const size_t    size;

public:
  VertexAttribute(
    const GLchar*   name,
    const GLint     count,
    const GLenum    type,
    const GLboolean norm
  ) : name(name)
    , count(count)
    , type(type)
    , norm(norm)
    , size(typeSize(type) * count) {}

  void definePointer(
    const GLuint  index,
    const GLsizei stride,
    const GLvoid* offset
  ) const {
    glEnableVertexAttribArray(index);
    glVertexAttribPointer(
      index,  // Index
      count,  // Count
      type,   // Type
      norm,   // Normalized
      stride, // Stride
      offset  // Offset of first value
    );
  }

  const size_t getSize() const {
    return size;
  }
};

static GLsizei stride(const vector<VertexAttribute>& attribs) {
  GLsizei stride = 0;

  for (const VertexAttribute& attrib : attribs)
    stride += attrib.getSize();

  return stride;
}

static void defineVertexPointers() {
  const static vector<VertexAttribute> attribs = {
    { "position", 3, GL_FLOAT, GL_FALSE },
    { "color"   , 3, GL_FLOAT, GL_TRUE  },
  };

  const static GLsizei STRIDE = stride(attribs);

  GLuint offset = 0;

  for (GLuint index = 0; index < attribs.size(); index++) {
    attribs[index].definePointer(index, STRIDE, (GLvoid*)offset);
    offset += attribs[index].getSize();
  }
}

struct VertexBufferObject : BufferObject {
  VertexBufferObject(
    const GLsizei dataSize,
    const GLvoid* data,
    const GLenum  usage
  ) : BufferObject(GL_ARRAY_BUFFER, dataSize, data, usage) {}

  void loadData() const override {
    BufferObject::loadData();
    defineVertexPointers();
  }
};

struct ElementBufferObject : BufferObject {
  ElementBufferObject(
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
    const VertexBufferObject&  vertexBufferObject,
    const ElementBufferObject& elementBufferObject
  ) : OpenGLData(newVertexArray()) {
    bind();
    vertexBufferObject.loadData();
    elementBufferObject.loadData();
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
