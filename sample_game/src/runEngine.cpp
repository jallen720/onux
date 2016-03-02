#include "runEngine.hpp"

#include <iostream>
#include <exception>
#include <glm/gtc/matrix_transform.hpp>

#include <GL/glew.h> // Required before other OpenGL headers

#include "environment/Environment.hpp"
#include "environment/Window.hpp"
#include "graphics/Camera.hpp"
#include "gl/utils/loadExtensions.hpp"
#include "gl/utils/configureOpenGL.hpp"
#include "engine/Entity.hpp"
#include "engine/GraphicsEngine.hpp"
#include "engine/Engine.hpp"
#include "resources/ResourceManager.hpp"
#include "assets/AssetManager.hpp"
#include "assets/Model.hpp"
#include "exceptions/Error.hpp"
#include "utils/UniqueMap.hpp"
#include "CameraControls.hpp"

using std::cerr;
using std::exception;
using glm::vec3;
using glm::perspective;
using glm::radians;
using onux::Environment;
using onux::Window;
using onux::Camera;
using onux::loadExtensions;
using onux::configureOpenGL;
using onux::Entity;
using onux::GraphicsEngine;
using onux::Engine;
using onux::ResourceManager;
using onux::AssetManager;
using onux::Model;
using onux::Error;
using onux::UniqueMap;

void runEngine() {
    try {
        // Environment creation
        Environment environment;
        Window window(1280, 720, "Onux");
        window.makeContextCurrent();
        loadExtensions();
        configureOpenGL();

        const ResourceManager   resourceManager("resources/");
        const AssetManager      assetManager(resourceManager);
        const UniqueMap<Model>& models = assetManager.getModels();

        // Drawable data
        GraphicsEngine::Entities entities {
            Entity(models["box.obj"]),
            Entity(models["heli.obj"]),
        };

        entities[0].getTransform().setPosition(vec3(0, 0, -6));
        entities[1].getTransform().setPosition(vec3(3, 0, -6));

        // Camera setup
        static const float FOV    = radians(45.0f);
        static const float Z_NEAR = 1.0f;
        static const float Z_FAR  = 500.0f;

        Camera camera(perspective(
            FOV,
            window.getAspectRatio(),
            Z_NEAR,
            Z_FAR
        ));

        // Engine setup
        CameraControls cameraControls(camera.getTransform(), window.getInput());
        GraphicsEngine graphicsEngine(entities, camera);
        Engine engine(window, graphicsEngine);
        engine.run();
    }
    catch (const exception& e) {
        cerr << "std::exception thrown: " << e.what() << "\n";
    }
    catch (...) {
        cerr << "Unknown exception thrown!\n";
    }
}
