#include "sampleEngine.hpp"

#include <GL/glew.h> // Must include before any OpenGL headers.

#include <iostream>

#include "Window.hpp"
#include "extensions.hpp"
#include "glHelpers.hpp"
#include "ShaderSource.hpp"
#include "ShaderObject.hpp"
#include "ShaderProgram.hpp"

using std::cout;
using std::cerr;
using std::endl;

#include "../resources/nonsense.hpp"
#include "../resources/data.hpp"

static const string SHADER_DIRECTORY = "resources/shaders/";

static const string shaderPath(const string& name) {
  return SHADER_DIRECTORY + name;
}

static float timeMod() {
  return fabs(sin(glfwGetTime() * 2.f));
}

static vec4 ourColor() {
  return vec4(0.f, timeMod(), 0.f, 1.f);
}

static void modifyColor(const ShaderProgram& shaderProgram) {
  shaderProgram.setUniform("ourColor", ourColor());
}

static void draw(const vector<const Renderable*>& renderables) {
  glClear(GL_COLOR_BUFFER_BIT);

  for (auto renderable : renderables) {
    renderable->enable();
    modifyColor(renderable->getShaderProgram());
    drawElements();
  }
}

static void checkGLError() {
  const GLenum error = glGetError();

  if (error != GL_NO_ERROR)
    throw runtime_error(
      "Unhandled OpenGL error generated:\n"
      "  " + getErrorMsg(error) + "\n\n"
    );
}

void sampleEngine() {
  try {
    // Environment creation
    Window window(1280, 720, "Onux");
    loadExtensions();
    glClearColor(1.f, 1.f, 1.f, 1.f);

    // Shader pipeline
    const ShaderSource shaderSources[] {
      ShaderSource(shaderPath("onux.vert")),
      ShaderSource(shaderPath("sample0.vert")),
      ShaderSource(shaderPath("sample1.vert")),
      ShaderSource(shaderPath("onux.frag")),
      ShaderSource(shaderPath("sample0.frag")),
    };

    const ShaderObject shaderObjects[] {
      ShaderObject(ShaderObject::Sources {
        &shaderSources[0],
        &shaderSources[1],
      }),
      ShaderObject(ShaderObject::Sources {
        &shaderSources[0],
        &shaderSources[2],
      }),
      ShaderObject(ShaderObject::Sources {
        &shaderSources[3],
        &shaderSources[4],
      }),
    };

    const ShaderProgram shaderPrograms[] {
      ShaderProgram(ShaderProgram::Objects {
        &shaderObjects[0],
        &shaderObjects[2],
      }),
      ShaderProgram(ShaderProgram::Objects {
        &shaderObjects[1],
        &shaderObjects[2],
      }),
    };

    // Vertex data
    const ElementBufferObject elementBufferObjects[] {
      ElementBufferObject(
        sizeof(elementData[0]),
        elementData[0],
        GL_STATIC_DRAW
      ),
    };

    const VertexBufferObject vertexBufferObjects[] {
      VertexBufferObject(
        sizeof(vertexData[0]),
        vertexData[0],
        GL_STATIC_DRAW
      ),
      VertexBufferObject(
        sizeof(vertexData[1]),
        vertexData[1],
        GL_STATIC_DRAW
      ),
    };

    const VertexArrayObject vertexArrayObjects[] {
      VertexArrayObject(
        vertexBufferObjects[0],
        elementBufferObjects[0]
      ),
      VertexArrayObject(
        vertexBufferObjects[1],
        elementBufferObjects[0]
      ),
    };

    // Renderable data
    const Renderable renderables[] {
      Renderable(
        vertexArrayObjects[0],
        shaderPrograms[0]
      ),
      Renderable(
        vertexArrayObjects[1],
        shaderPrograms[1]
      ),
    };

    const vector<const Renderable*> drawables {
      &renderables[0],
      &renderables[1],
    };

    // Engine loop
    cout << "Running engine...\n";
    checkGLError();

    while (!window.shouldClose()) {
      glfwPollEvents();
      draw(drawables);
      window.swapBuffers();
      checkGLError();
    }
  } catch(const runtime_error& e) {
    cerr << e.what() << endl;
  } catch(...) {
    cerr << "Unknown exception thrown!\n";
  }
}
