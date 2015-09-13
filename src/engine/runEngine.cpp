#include "engine/runEngine.hpp"

#include <GL/glew.h> // Must include before any OpenGL headers.

#include <iostream>
#include <stdexcept>
#include <string>
#include <glm/gtc/matrix_transform.hpp>

#include "Environment.hpp"
#include "Window.hpp"
#include "extensions.hpp"
#include "graphics/ShaderSource.hpp"
#include "graphics/Image.hpp"
#include "graphics/Scene.hpp"
#include "graphics/Camera.hpp"
#include "gl/ShaderObject.hpp"
#include "gl/ShaderProgram.hpp"
#include "gl/VertexBuffer.hpp"
#include "gl/IndexBuffer.hpp"
#include "gl/VertexArray.hpp"
#include "gl/Texture.hpp"
#include "engine/Renderable.hpp"
#include "engine/GraphicsEngine.hpp"
#include "engine/Engine.hpp"

using std::cerr;
using std::endl;
using std::runtime_error;
using std::string;
using glm::vec3;
using glm::perspective;
using glm::radians;

using onux::Environment;
using onux::Window;
using onux::loadExtensions;
using onux::ShaderSource;
using onux::Image;
using onux::Scene;
using onux::Camera;
using onux::ShaderObject;
using onux::ShaderProgram;
using onux::VertexBuffer;
using onux::IndexBuffer;
using onux::VertexArray;
using onux::Texture;
using onux::Renderable;
using onux::GraphicsEngine;
using onux::Engine;

static const string SHADER_DIRECTORY = "resources/shaders/";
static const string IMAGE_DIRECTORY  = "resources/images/";
static const string SCENE_DIRECTORY  = "resources/models/";

static const string shaderPath(const string& name) {
  return SHADER_DIRECTORY + name;
}

static const string imagePath(const string& name) {
  return IMAGE_DIRECTORY + name;
}

static const string scenePath(const string& name) {
  return SCENE_DIRECTORY + name;
}

static void configOpenGL() {
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glCullFace(GL_BACK);
  glEnable(GL_CULL_FACE);
  glEnable(GL_DEPTH_TEST);
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

    // Drawable data
    const Scene scenes[] {
      { scenePath("hheli.obj") },
      { scenePath("cube.obj")  },
    };

    Renderable renderables[] {
      Renderable(
        scenes[0].getMeshes()[0],
        shaderPrograms[1],
        { &textures[2] }
      ),
      Renderable(
        scenes[1].getMeshes()[0],
        shaderPrograms[0],
        { &textures[0], &textures[1] }
      ),
    };

    renderables[1].getTransform().setPosition(vec3(0, 0, -5));
    renderables[0].getTransform().setScale(vec3(0.025));
    renderables[0].getTransform().setPosition(vec3(2, -1, -5));
    renderables[0].getTransform().setRotation(vec3(0, 90, 0));

    const GraphicsEngine::Drawables drawables {
      &renderables[0],
      &renderables[1],
    };

    // Camera setup
    static const float FOV    = radians(45.f);
    static const float Z_NEAR = 1.f;
    static const float Z_FAR  = 500.f;
    Camera camera(perspective(FOV, window.getAspect(), Z_NEAR, Z_FAR));

    GraphicsEngine graphicsEngine(drawables, camera);

    // Engine
    Engine engine(window, graphicsEngine);
    engine.run();

  } catch(const runtime_error& e) {
    cerr << e.what() << endl;
  } catch(...) {
    cerr << "Unknown exception thrown!\n";
  }
}
