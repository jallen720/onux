#include "runEngine.hpp"

#include <iostream>
#include <vector>
#include <memory>
#include <exception>
#include <glm/gtc/matrix_transform.hpp>

#include <GL/glew.h> // Required before other OpenGL headers

#include "environment/Environment.hpp"
#include "environment/Window.hpp"

#include "graphics/Camera.hpp"
#include "graphics/Shader.hpp"

#include "gl/ShaderObject.hpp"
#include "gl/ShaderProgram.hpp"
#include "gl/Texture.hpp"
#include "gl/utils/loadExtensions.hpp"
#include "gl/utils/configureOpenGL.hpp"

#include "engine/Renderable.hpp"
#include "engine/GraphicsEngine.hpp"
#include "engine/Engine.hpp"

#include "resources/ResourceManager.hpp"
#include "resources/containers/Shaders.hpp"
#include "resources/containers/Images.hpp"
#include "resources/containers/Models.hpp"

#include "exceptions/Error.hpp"

#include "CameraControls.hpp"

using std::cerr;
using std::vector;
using std::unique_ptr;
using std::exception;

using glm::vec3;
using glm::perspective;
using glm::radians;

using onux::Environment;
using onux::Window;

using onux::Camera;
using onux::Shader;

using onux::ShaderObject;
using onux::ShaderProgram;
using onux::Texture;
using onux::loadExtensions;
using onux::configureOpenGL;

using onux::Renderable;
using onux::GraphicsEngine;
using onux::Engine;

using onux::ResourceManager;
using onux::Shaders;
using onux::Images;
using onux::Models;

using onux::Error;

void runEngine() {
    try {
        // Environment creation
        Environment environment;
        Window window(1280, 720, "Onux");
        window.makeContextCurrent();
        loadExtensions();
        configureOpenGL();

        // Resources
        const ResourceManager resourceManager;
        const Shaders& shaders = resourceManager.getShaders();
        const Images& images = resourceManager.getImages();
        const Models& models = resourceManager.getModels();

        shaders["multiTexture.yaml"]->getProgram().use();
        shaders["multiTexture.yaml"]->getProgram().setUniform("texture1", 1);

        // Textures
        vector<unique_ptr<Texture>> textures;
        textures.emplace_back(new Texture(images["box.jpg"]));
        textures.emplace_back(new Texture(images["bricks.png"]));
        textures.emplace_back(new Texture(images["hheli.bmp"]));

        // Drawable data
        Renderable renderables[] {
            Renderable(
                models["hheli.obj"]->getMeshes()[0],
                shaders["diffuse.yaml"]->getProgram(),

                {
                    textures[2].get(),
                }
            ),

            Renderable(
                models["cube.obj"]->getMeshes()[0],
                shaders["multiTexture.yaml"]->getProgram(),

                {
                    textures[0].get(),
                    textures[1].get(),
                }
            ),

            Renderable(
                models["hheli.obj"]->getMeshes()[0],
                shaders["diffuse.yaml"]->getProgram(),

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
