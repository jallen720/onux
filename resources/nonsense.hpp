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
  const GLenum target;
  const GLsizei dataSize;
  const GLvoid* data;
  const GLenum usage;

protected:
  BufferObject(
    const GLenum target,
    const GLsizei dataSize,
    const GLvoid* data,
    const GLenum usage
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

  const size_t getSize() const {
    return size;
  }

  void definePointer(
    const GLuint  index,
    const GLsizei stride,
    const GLvoid* first
  ) const {
    glEnableVertexAttribArray(index);
    glVertexAttribPointer(
      index,  // Index
      count,  // Count
      type,   // Type
      norm,   // Normalized
      stride, // Stride
      first   // Pointer to first value
    );
  }
};

static GLsizei stride(const vector<VertexAttribute>& attributes) {
  GLsizei stride = 0;

  for (auto attribute : attributes)
    stride += attribute.getSize();

  return stride;
}

static void defineVertexPointers() {
  const static vector<VertexAttribute> attributes = {
    { "position", 3, GL_FLOAT, GL_FALSE },
    { "color"   , 3, GL_FLOAT, GL_TRUE  },
  };

  const static GLsizei STRIDE = stride(attributes);

  for (GLuint i = 0, p = 0; i < attributes.size(); p += attributes[i].getSize(), i++)
    attributes[i].definePointer(i, STRIDE, (GLvoid*)p);
}

struct VertexBufferObject : BufferObject {
  VertexBufferObject(const GLsizei dataSize, const GLvoid* data, const GLenum usage)
    : BufferObject(GL_ARRAY_BUFFER, dataSize, data, usage) {}

  void loadData() const override {
    BufferObject::loadData();
    defineVertexPointers();
  }
};

struct ElementBufferObject : BufferObject {
  ElementBufferObject(const GLsizei dataSize, const GLvoid* data, const GLenum usage)
    : BufferObject(GL_ELEMENT_ARRAY_BUFFER, dataSize, data, usage) {}
};

static GLuint newVertexArray() {
  GLuint id;
  glGenVertexArrays(1, &id);
  return id;
}

struct VertexArrayObject : public OpenGLData {
  VertexArrayObject(
    const VertexBufferObject& vbo,
    const ElementBufferObject& ebo
  ) : OpenGLData(newVertexArray()) {
    bind();
    vbo.loadData();
    ebo.loadData();
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

static const bool isLocation(const GLint location) {
  const static GLint UNKNOWN_LOCATION = -1;
  return location != UNKNOWN_LOCATION;
}

static void logUnknownLocation(const string& type, const string& name) {
  throw runtime_error(
    "Failed to find location for uniform "
    + type + " named \"" + name + "\"!"
  );
}

class ShaderProgram : OpenGLData {
  void attach(const vector<const ShaderObject*>& shaderObjects) const {
    for (auto shaderObject : shaderObjects)
      glAttachShader(getID(), shaderObject->getID());
  }

  void link() const {
    glLinkProgram(getID());
  }

  void detach(const vector<const ShaderObject*>& shaderObjects) const {
    for (auto shaderObject : shaderObjects)
      glDetachShader(getID(), shaderObject->getID());
  }

  const GLint getUniformLocation(const GLchar* name) const {
    return glGetUniformLocation(getID(), name);
  }

public:
  ShaderProgram(const vector<const ShaderObject*>& shaderObjects)
    : OpenGLData(glCreateProgram()) {
    attach(shaderObjects);
    link();
    detach(shaderObjects);
    logCreation(this, "ShaderProgram");
  }

  ~ShaderProgram() {
    logDestruction(this, "ShaderProgram");
    glDeleteProgram(getID());
  }

  void use() const {
    glUseProgram(getID());
  }

  void setUniform(const GLchar* name, const vec4& value) const {
    const GLint location = getUniformLocation(name);

    if (isLocation(location))
      glUniform4f(location, value.x, value.y, value.z, value.w);
    else
      logUnknownLocation("vec4", name);
  }
};

static void drawElements() {
  const static GLenum  MODE     = GL_TRIANGLE_STRIP;
  const static GLsizei COUNT    = 6;
  const static GLenum  TYPE     = GL_UNSIGNED_INT;
  const static GLvoid* POINTER  = 0;

  glDrawElements(
    MODE,
    COUNT,
    TYPE,
    POINTER
  );
}

static uint id = 0;

class Renderable {
  const VertexArrayObject& vertexArray;
  const ShaderProgram& shaderProgram;
  const uint myID;

public:
  Renderable(
    const VertexArrayObject& vertexArray,
    const ShaderProgram& shaderProgram
  ) : vertexArray(vertexArray)
    , shaderProgram(shaderProgram)
    , myID(id++) {
    cout << "Renderable [" << myID << "] created\n";
  }

  ~Renderable() {
    cout << "Renderable [" << myID << "] destroyed\n";
  }

  void enable() const {
    vertexArray.bind();
    shaderProgram.use();
  }

  const ShaderProgram& getShaderProgram() const {
    return shaderProgram;
  }
};
