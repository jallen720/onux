#include "sampleEngine.hpp"

#include <GL/glew.h> // Must include before any OpenGL headers.

#include <iostream>
#include <stdexcept>
#include <thread>
#include <chrono>

#include "Window.hpp"
#include "extensions.hpp"
#include "ShaderSource.hpp"
#include "Image.hpp"
#include "onux_gl/helpers.hpp"
#include "onux_gl/ShaderObject.hpp"
#include "onux_gl/ShaderProgram.hpp"
#include "onux_gl/Vertex.hpp"
#include "onux_gl/VertexBuffer.hpp"
#include "onux_gl/IndexBuffer.hpp"
#include "onux_gl/VertexArray.hpp"
#include "onux_gl/Texture.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::runtime_error;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;
using namespace onux_gl;

class Renderable {
public:
  typedef const vector<const Texture*> Textures;

private:
  const VertexArray& vertexArray;
  const ShaderProgram& shaderProgram;
  Textures textures;

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
    bindTextures();
  }

  const ShaderProgram& getShaderProgram() const {
    return shaderProgram;
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

static vec3 objectPosition() {
  return vec3(sin(glfwGetTime() / 2.f) / 2.f, 0.f, 0.f);
}

static void setUniforms(const ShaderProgram& shaderProgram) {
  shaderProgram.setUniform("objectPosition", objectPosition());
}

static void drawElements() {
  static const GLenum  MODE  = GL_TRIANGLE_STRIP;
  static const GLsizei COUNT = 6;
  static const GLenum  TYPE  = GL_UNSIGNED_INT;
  static const GLvoid* FIRST = 0;
  glDrawElements(MODE, COUNT, TYPE, FIRST);
}

static void draw(const vector<const Renderable*>& renderables) {
  glClear(GL_COLOR_BUFFER_BIT);

  for (auto renderable : renderables) {
    renderable->enable();
    setUniforms(renderable->getShaderProgram());
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
    const ShaderSource shaderSources[] {
      ShaderSource(shaderPath("onux.vert")),
      ShaderSource(shaderPath("sample0.vert")),
      ShaderSource(shaderPath("sample1.vert")),
      ShaderSource(shaderPath("onux.frag")),
      ShaderSource(shaderPath("sample0.frag")),
      ShaderSource(shaderPath("sample1.frag")),
    };

    const ShaderObject shaderObjects[] {
      ShaderObject({ &shaderSources[0], &shaderSources[1] }),
      ShaderObject({ &shaderSources[0], &shaderSources[2] }),
      ShaderObject({ &shaderSources[3], &shaderSources[4] }),
      ShaderObject({ &shaderSources[3], &shaderSources[5] }),
    };

    const ShaderProgram shaderPrograms[] {
      ShaderProgram({ &shaderObjects[0], &shaderObjects[2] }),
      ShaderProgram({ &shaderObjects[1], &shaderObjects[3] }),
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
    const Renderable renderables[] {
      Renderable(vertexArrays[0], shaderPrograms[0], { &textures[1], &textures[0] }),
      Renderable(vertexArrays[1], shaderPrograms[1], { &textures[0] }),
    };

    const vector<const Renderable*> drawables {
      &renderables[0],
      &renderables[1],
    };

    // Engine loop
    cout << "Running engine...\n";
    checkGLError(glGetError());

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
