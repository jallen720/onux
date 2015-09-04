#include "sampleEngine.hpp"

#include <GL/glew.h> // Must include before any OpenGL headers.

#include <iostream>
#include <stdexcept>
#include <vector>
#include <thread>
#include <chrono>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Window.hpp"
#include "extensions.hpp"
#include "ShaderSource.hpp"
#include "Image.hpp"
#include "Transform.hpp"
#include "ViewTransform.hpp"
#include "Scene.hpp"
#include "Mesh.hpp"
#include "Camera.hpp"
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
using std::vector;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;
using glm::vec2;
using glm::vec3;
using glm::vec4;
using glm::perspective;
using glm::radians;
using onux_gl::getErrorMsg;
using onux_gl::ShaderObject;
using onux_gl::ShaderProgram;
using onux_gl::Vertex;
using onux_gl::VertexBuffer;
using onux_gl::IndexBuffer;
using onux_gl::VertexArray;
using onux_gl::Texture;

static const string SHADER_DIRECTORY = "resources/shaders/";
static const string IMAGE_DIRECTORY = "resources/images/";
static const string SCENE_DIRECTORY = "resources/models/";

static const string shaderPath(const string& name) {
  return SHADER_DIRECTORY + name;
}

static const string imagePath(const string& name) {
  return IMAGE_DIRECTORY + name;
}

static const string scenePath(const string& name) {
  return SCENE_DIRECTORY + name;
}

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

  void setUniforms(
    const mat4& model,
    const mat4& view,
    const mat4& projection
  ) const {
    shaderProgram.setUniform("model"     , model     , GL_FALSE);
    shaderProgram.setUniform("view"      , view      , GL_FALSE);
    shaderProgram.setUniform("projection", projection, GL_FALSE);
  }

public:
  Renderable(
    const VertexArray& vertexArray,
    const ShaderProgram& shaderProgram,
    Textures textures
  ) : vertexArray(vertexArray)
    , shaderProgram(shaderProgram)
    , textures(textures) {}

  void enable(Camera& camera) const {
    vertexArray.bind();
    shaderProgram.use();

    setUniforms(
      transform.getMatrix(),
      camera.getViewTransform().getMatrix(),
      camera.getProjection()
    );

    bindTextures();
  }

  const ShaderProgram& getShaderProgram() const {
    return shaderProgram;
  }

  Transform& getTransform() {
    return transform;
  }
};

static GLsizei indexCount;

static void drawElements() {
  static const GLenum  MODE  = GL_TRIANGLES;
  static const GLenum  TYPE  = GL_UNSIGNED_INT;
  static const GLvoid* FIRST = 0;
  glDrawElements(MODE, indexCount, TYPE, FIRST);
}

static void draw(const vector<Renderable*>& drawables, Camera& camera) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  for (auto drawable : drawables) {
    drawable->enable(camera);
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

static void configOpenGL() {
  glClearColor(1, 1, 1, 1);
  glCullFace(GL_BACK);
  glEnable(GL_CULL_FACE);
  glEnable(GL_DEPTH_TEST);
}

void sampleEngine() {
  try {
    // Environment creation
    Window window(1280, 720, "Onux");
    loadExtensions();
    configOpenGL();

    // Shaders
    const ShaderSource onuxVertHeader(shaderPath("onux.vert"));
    const ShaderSource onuxFragHeader(shaderPath("onux.frag"));

    const ShaderSource vertSources[] {
      { shaderPath("sample0.vert") },
      { shaderPath("sample1.vert") },
    };

    const ShaderSource fragSources[] {
      { shaderPath("sample0.frag") },
      { shaderPath("sample1.frag") },
    };

    const ShaderObject vertObjects[] {
      { { &onuxVertHeader, &vertSources[0] } },
      { { &onuxVertHeader, &vertSources[1] } },
    };

    const ShaderObject fragObjects[] {
      { { &onuxFragHeader, &fragSources[0] } },
      { { &onuxFragHeader, &fragSources[1] } },
    };

    const ShaderProgram shaderPrograms[] {
      { { &vertObjects[0], &fragObjects[0] } },
      { { &vertObjects[1], &fragObjects[1] } },
    };

    shaderPrograms[0].use();
    shaderPrograms[0].setUniform("texture1", 1);

    // Textures
    const Image images[] {
      { imagePath("box.jpg")    },
      { imagePath("bricks.png") },
      { imagePath("hheli.bmp")  },
    };

    const Texture textures[] {
      { images[0] },
      { images[1] },
      { images[2] },
    };

    // Renderable data
    const Scene scene(scenePath("cube.obj"));
    // const Scene scene(scenePath("hheli.obj"));
    auto meshes   = scene.getMeshes();
    auto vertexes = meshes[0].getVertexes();
    auto indexes  = meshes[0].getIndexes();
    indexCount    = indexes.size();

    const VertexBuffer vertexBuffers[] {
      { sizeof(Vertex) * vertexes.size(), &vertexes[0], GL_STATIC_DRAW },
    };

    const IndexBuffer indexBuffers[] {
      { sizeof(GLuint) * indexes.size(), &indexes[0], GL_STATIC_DRAW },
    };

    const VertexArray vertexArrays[] {
      { vertexBuffers[0], indexBuffers[0] },
    };

    // Renderable data
    Renderable renderables[] {
      { vertexArrays[0], shaderPrograms[1], { &textures[0] } },
    };

    const vector<Renderable*> drawables {
      &renderables[0],
    };

    drawables[0]->getTransform().setPosition(vec3(0, 0, -4));

    // Camera setup
    static const float FOV        = radians(45.f);
    static const float ASPECT     = 1280.f / 720.f;
    static const float Z_NEAR     = 1.f;
    static const float Z_FAR      = 500.f;
    static const mat4  PROJECTION = perspective(FOV, ASPECT, Z_NEAR, Z_FAR);
    Camera camera(PROJECTION);
    camera.getViewTransform().setPosition(vec3(2, 0, 0));
    camera.getViewTransform().setRotation(vec3(10, 0, 0));

    // Check for gl errors generated during resource initialization.
    checkGLError(glGetError());

    // Engine loop
    float frameStart = glfwGetTime();

    while (!window.shouldClose()) {
      glfwPollEvents();
      draw(drawables, camera);
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
