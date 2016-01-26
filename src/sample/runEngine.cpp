#include "sample/runEngine.hpp"

#include <iostream>
#include <vector>
#include <memory>
#include <exception>
#include <glm/gtc/matrix_transform.hpp>

#include <GL/glew.h> // Required before other OpenGL headers

#include "environment/Environment.hpp"
#include "environment/Window.hpp"
#include "environment/loadExtensions.hpp"

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
#include "resources/containers/Scenes.hpp"

#include "exceptions/Error.hpp"

#include "sample/CameraControls.hpp"

using std::cerr;
using std::vector;
using std::unique_ptr;
using std::exception;
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
using onux::Scenes;

using onux::Error;

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
        Scenes scenes;

        // Shaders
        vector<unique_ptr<ShaderObject>> vertObjects;

        vertObjects.emplace_back(new ShaderObject({
            shaderSources["onux.vert"],
            shaderSources["sample0.vert"],
        }));

        vertObjects.emplace_back(new ShaderObject({
            shaderSources["onux.vert"],
            shaderSources["sample1.vert"],
        }));

        vector<unique_ptr<ShaderObject>> fragObjects;

        fragObjects.emplace_back(new ShaderObject({
            shaderSources["onux.frag"],
            shaderSources["sample0.frag"],
        }));

        fragObjects.emplace_back(new ShaderObject({
            shaderSources["onux.frag"],
            shaderSources["sample1.frag"],
        }));

        vector<unique_ptr<ShaderProgram>> shaderPrograms;

        shaderPrograms.emplace_back(new ShaderProgram({
            vertObjects[0].get(),
            fragObjects[0].get(),
        }));

        shaderPrograms.emplace_back(new ShaderProgram({
            vertObjects[1].get(),
            fragObjects[1].get(),
        }));

        shaderPrograms[0]->use();
        shaderPrograms[0]->setUniform("texture1", 1);

        // Textures
        vector<unique_ptr<Texture>> textures;
        textures.emplace_back(new Texture(images["box.jpg"]));
        textures.emplace_back(new Texture(images["bricks.png"]));
        textures.emplace_back(new Texture(images["hheli.bmp"]));

        // Drawable data
        Renderable renderables[] {
            Renderable(
                scenes["hheli.obj"]->getMeshes()[0],
                *shaderPrograms[1].get(),
                {
                    textures[2].get(),
                }
            ),
            Renderable(
                scenes["cube.obj"]->getMeshes()[0],
                *shaderPrograms[0].get(),
                {
                    textures[0].get(),
                    textures[1].get(),
                }
            ),
            Renderable(
                scenes["hheli.obj"]->getMeshes()[0],
                *shaderPrograms[1].get(),
                {
                    textures[2].get(),
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
    }
    catch (const exception& e) {
        cerr << e.what() << "\n";
    }
    catch (...) {
        cerr << "Unknown exception thrown!\n";
    }
}
