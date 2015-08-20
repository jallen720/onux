#include "sampleEngine.hpp"

#include <GL/glew.h> // Must include before any OpenGL headers.

#include <iostream>
#include <stdexcept>
#include <vector>
#include <thread>
#include <chrono>
#include <glm/glm.hpp>

#include "Window.hpp"
#include "extensions.hpp"
#include "ShaderSource.hpp"
#include "Image.hpp"
#include "Transform.hpp"
#include "onux_gl/helpers.hpp"
#include "onux_gl/ShaderObject.hpp"
#include "onux_gl/ShaderProgram.hpp"
#include "onux_gl/Vertex.hpp"
#include "onux_gl/VertexBuffer.hpp"
#include "onux_gl/IndexBuffer.hpp"
#include "onux_gl/VertexArray.hpp"
#include "onux_gl/Texture.hpp"

using std::cerr;
using std::endl;
using std::runtime_error;
using std::vector;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;
using glm::vec3;
using glm::vec4;
using onux_gl::getErrorMsg;
using onux_gl::ShaderObject;
using onux_gl::ShaderProgram;
using onux_gl::Vertex;
using onux_gl::VertexBuffer;
using onux_gl::IndexBuffer;
using onux_gl::VertexArray;
using onux_gl::Texture;

class Renderable {
public:
  typedef const vector<const Texture*> Textures;

private:
  const VertexArray& vertexArray;
  const ShaderProgram& shaderProgram;
  Textures textures;
  Transform transform;

  void bindTextures() const {
    for (unsigned int i = 0; i < textures.size(); i++)
      textures[i]->bind(i);
  }

public:
  Renderable(
    const VertexArray& vertexArray,
    const ShaderProgram& shaderProgram,
    Textures textures
  ) : vertexArray(vertexArray)
    , shaderProgram(shaderProgram)
    , textures(textures) {}

  void enable() const {
    vertexArray.bind();
    shaderProgram.use();
    shaderProgram.setUniform("transform", transform.getMatrix(), GL_FALSE);
    bindTextures();
  }

  const ShaderProgram& getShaderProgram() const {
    return shaderProgram;
  }

  Transform& getTransform() {
    return transform;
  }
};

static const string SHADER_DIRECTORY = "resources/shaders/";
static const string IMAGE_DIRECTORY = "resources/images/";

static const string shaderPath(const string& name) {
  return SHADER_DIRECTORY + name;
}

static const string imagePath(const string& name) {
  return IMAGE_DIRECTORY + name;
}

static void drawElements() {
  static const GLenum  MODE  = GL_TRIANGLE_STRIP;
  static const GLsizei COUNT = 6;
  static const GLenum  TYPE  = GL_UNSIGNED_INT;
  static const GLvoid* FIRST = 0;
  glDrawElements(MODE, COUNT, TYPE, FIRST);
}

static void draw(const vector<Renderable*>& renderables) {
  glClear(GL_COLOR_BUFFER_BIT);

  for (auto renderable : renderables) {
    renderable->getTransform().translate(vec3(0.001f, 0, 0));
    renderable->enable();
    drawElements();
  }
}

static void checkGLError(const GLenum error) {
  if (error != GL_NO_ERROR)
    throw runtime_error(
      "Unhandled OpenGL error generated:\n"
      "  " + getErrorMsg(error) + "\n\n"
    );
}

static void frameWait(float frameStart) {
  static const float FPS  = 60.f;
  long wait = ((1.f / FPS) * 1000) - (glfwGetTime() - frameStart);
  sleep_for(milliseconds(wait));
}

static const vec4 WHITE = vec4(1, 1, 1, 1);

void sampleEngine() {
  try {
    // Environment creation
    Window window(1280, 720, "Onux");
    loadExtensions();
    glClearColor(1, 1, 1, 1);

    // Vertex data
    const GLuint VERTEXES_PER_ARRAY = 4;

    const Vertex vertexData[][VERTEXES_PER_ARRAY] {
      {
        Vertex({-0.7f,-0.9f, 0 }, WHITE, { 0, 0 }), // Bottom left
        Vertex({-0.9f, 0.9f, 0 }, WHITE, { 0, 1 }), // Top left
        Vertex({-0.1f, 0.3f, 0 }, WHITE, { 1, 1 }), // Top right
        Vertex({-0.1f,-0.9f, 0 }, WHITE, { 1, 0 }), // Bottom right
      }, {
        Vertex({ 0.1f,-0.8f, 0 }, WHITE, { 0, 0 }), // Bottom left
        Vertex({ 0.1f, 0.9f, 0 }, WHITE, { 0, 1 }), // Top left
        Vertex({ 0.4f, 0.9f, 0 }, WHITE, { 1, 1 }), // Top right
        Vertex({ 0.9f,-0.9f, 0 }, WHITE, { 1, 0 }), // Bottom right
      },
    };

    const GLuint indexData[] {
      0, 1, 2,
      0, 2, 3,
    };

    const IndexBuffer indexBuffers[] {
      IndexBuffer(sizeof(indexData), indexData, GL_STATIC_DRAW),
    };

    const VertexBuffer vertexBuffers[] {
      VertexBuffer(sizeof(vertexData[0]), vertexData[0], GL_STATIC_DRAW),
      VertexBuffer(sizeof(vertexData[1]), vertexData[1], GL_STATIC_DRAW),
    };

    const VertexArray vertexArrays[] {
      VertexArray(vertexBuffers[0], indexBuffers[0]),
      VertexArray(vertexBuffers[1], indexBuffers[0]),
    };

    // Shaders
    const ShaderSource onuxVertHeader(shaderPath("onux.vert"));
    const ShaderSource onuxFragHeader(shaderPath("onux.frag"));

    const ShaderSource vertSources[] {
      ShaderSource(shaderPath("sample0.vert")),
      ShaderSource(shaderPath("sample1.vert")),
    };

    const ShaderSource fragSources[] {
      ShaderSource(shaderPath("sample0.frag")),
      ShaderSource(shaderPath("sample1.frag")),
    };

    const ShaderObject vertObjects[] {
      ShaderObject({ &onuxVertHeader, &vertSources[0] }),
      ShaderObject({ &onuxVertHeader, &vertSources[1] }),
    };

    const ShaderObject fragObjects[] {
      ShaderObject({ &onuxFragHeader, &fragSources[0] }),
      ShaderObject({ &onuxFragHeader, &fragSources[1] }),
    };

    const ShaderProgram shaderPrograms[] {
      ShaderProgram({ &vertObjects[0], &fragObjects[0] }),
      ShaderProgram({ &vertObjects[1], &fragObjects[1] }),
    };

    shaderPrograms[0].use();
    shaderPrograms[0].setUniform("texture1", 1);

    // Textures
    const Image images[] {
      Image(imagePath("box.jpg")),
      Image(imagePath("bricks.png")),
    };

    const Texture textures[] {
      Texture(images[0]),
      Texture(images[1]),
    };

    // Renderable data
    Renderable renderables[] {
      Renderable(vertexArrays[0], shaderPrograms[0], { &textures[1], &textures[0] }),
      Renderable(vertexArrays[1], shaderPrograms[1], { &textures[0] }),
    };

    const vector<Renderable*> drawables {
      &renderables[0],
      &renderables[1],
    };

    checkGLError(glGetError());

    // Engine loop
    float frameStart = glfwGetTime();

    while (!window.shouldClose()) {
      glfwPollEvents();
      draw(drawables);
      window.swapBuffers();
      checkGLError(glGetError());
      frameWait(frameStart);
      frameStart = glfwGetTime();
    }
  } catch(const runtime_error& e) {
    cerr << e.what() << endl;
  } catch(...) {
    cerr << "Unknown exception thrown!\n";
  }
}
