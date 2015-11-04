#include "sample/runEngine.hpp"

#include <iostream>
#include <stdexcept>
#include <glm/gtc/matrix_transform.hpp>

#include <GL/glew.h> // Required before other OpenGL headers

#include "environment/Environment.hpp"
#include "environment/Window.hpp"
#include "environment/extensions.hpp"

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

#include "resources/containers/ShaderSources.hpp"
#include "resources/containers/Images.hpp"
#include "resources/containers/Models.hpp"

#include "sample/CameraControls.hpp"

using std::cerr;
using std::runtime_error;
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

using onux::ShaderSources;
using onux::Images;
using onux::Models;

static void configureOpenGL() {
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
    window.makeContextCurrent();
    loadExtensions();
    configureOpenGL();

    // Resources
    ShaderSources shaderSources;
    Images images;
    Models models;

    // Shaders
    const ShaderObject vertObjects[] {
      ShaderObject({
        shaderSources["onux.vert"],
        shaderSources["sample0.vert"],
      }),
      ShaderObject({
        shaderSources["onux.vert"],
        shaderSources["sample1.vert"],
      }),
    };

    const ShaderObject fragObjects[] {
      ShaderObject({
        shaderSources["onux.frag"],
        shaderSources["sample0.frag"],
      }),
      ShaderObject({
        shaderSources["onux.frag"],
        shaderSources["sample1.frag"],
      }),
    };

    const ShaderProgram shaderPrograms[] {
      ShaderProgram({
        &vertObjects[0],
        &fragObjects[0],
      }),
      ShaderProgram({
        &vertObjects[1],
        &fragObjects[1],
      }),
    };

    shaderPrograms[0].use();
    shaderPrograms[0].setUniform("texture1", 1);

    // Textures
    const Texture textures[] {
      { images["box.jpg"]    },
      { images["bricks.png"] },
      { images["hheli.bmp"]  },
    };

    // Drawable data
    Renderable renderables[] {
      Renderable(
        models["hheli.obj"]->getMeshes()[0],
        shaderPrograms[1],
        {
          &textures[2]
        }
      ),
      Renderable(
        models["cube.obj"]->getMeshes()[0],
        shaderPrograms[0],
        {
          &textures[0],
          &textures[1],
        }
      ),
      Renderable(
        models["hheli.obj"]->getMeshes()[0],
        shaderPrograms[1],
        {
          &textures[2],
        }
      ),
    };

    renderables[1]
      .getTransform()
      .setPosition(vec3(0, 0, -5));

    renderables[0]
      .getTransform()
      .setScale(vec3(0.025f));

    renderables[0]
      .getTransform()
      .setPosition(vec3(2, -1, -5));

    renderables[0]
      .getTransform()
      .setRotation(vec3(0, 90, 0));

    renderables[2]
      .getTransform()
      .setScale(vec3(0.025f));

    renderables[2]
      .getTransform()
      .setPosition(vec3(-2, -1, -5));

    renderables[2]
      .getTransform()
      .setRotation(vec3(0, 90, 0));

    GraphicsEngine::Drawables drawables {
      &renderables[0],
      &renderables[1],
      &renderables[2],
    };

    // Camera setup
    static const float FOV    = radians(45.0f);
    static const float Z_NEAR = 1.0f;
    static const float Z_FAR  = 500.0f;
    Camera camera(perspective(FOV, window.getAspect(), Z_NEAR, Z_FAR));

    // Engine setup
    CameraControls cameraControls(camera.getTransform(), window.getInput());
    GraphicsEngine graphicsEngine(drawables, camera);
    Engine engine(window, graphicsEngine);
    engine.run();
  } catch(const runtime_error& e) {
    cerr << e.what() << "\n";
  } catch(...) {
    cerr << "Unknown exception thrown!\n";
  }
}
