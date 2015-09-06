#include "sample/engine.hpp"

#include <GL/glew.h> // Must include before any OpenGL headers.

#include <iostream>
#include <stdexcept>
#include <string>
#include <thread>
#include <chrono>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

#include "Environment.hpp"
#include "Window.hpp"
#include "extensions.hpp"
#include "ShaderSource.hpp"
#include "Image.hpp"
#include "Transform.hpp"
#include "ViewTransform.hpp"
#include "Scene.hpp"
#include "Camera.hpp"
#include "onux_gl/helpers.hpp"
#include "onux_gl/ShaderObject.hpp"
#include "onux_gl/ShaderProgram.hpp"
#include "onux_gl/VertexBuffer.hpp"
#include "onux_gl/IndexBuffer.hpp"
#include "onux_gl/VertexArray.hpp"
#include "sample/Renderable.hpp"
#include "sample/RenderingEngine.hpp"

using std::cerr;
using std::endl;
using std::runtime_error;
using std::string;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;
using glm::perspective;
using glm::radians;
using onux_gl::getErrorMsg;
using onux_gl::ShaderObject;
using onux_gl::ShaderProgram;
using onux_gl::VertexBuffer;
using onux_gl::IndexBuffer;
using onux_gl::VertexArray;

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

static void engineLoop(const Window& window, RenderingEngine& renderingEngine) {
  auto frameStart = glfwGetTime();

  while (!window.shouldClose()) {
    glfwPollEvents();
    renderingEngine.render();
    window.swapBuffers();
    checkGLError(glGetError());
    frameWait(frameStart);
    frameStart = glfwGetTime();
  }
}

void runEngine() {
  try {
    // Environment creation
    Environment environment;
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

    renderables[0].getTransform().setPosition(vec3(0, 0, -4));

    const RenderingEngine::Drawables drawables {
      &renderables[0],
    };

    // Camera setup
    static const float FOV        = radians(45.f);
    static const float Z_NEAR     = 1.f;
    static const float Z_FAR      = 500.f;
    static const mat4  PROJECTION = perspective(
      FOV,
      window.getAspect(),
      Z_NEAR,
      Z_FAR
    );

    Camera camera(PROJECTION);
    camera.getViewTransform().setPosition(vec3(1.2, 0, 0));
    camera.getViewTransform().setRotation(vec3(10, 0, 0));

    RenderingEngine renderingEngine(drawables, camera);

    // Check for gl errors generated during resource initialization.
    checkGLError(glGetError());

    // Engine loop
    engineLoop(window, renderingEngine);
  } catch(const runtime_error& e) {
    cerr << e.what() << endl;
  } catch(...) {
    cerr << "Unknown exception thrown!\n";
  }
}
