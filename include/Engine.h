#pragma once

#include <cstdint>
#include <memory>
#include <vector>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "IRenderable.h"
#include "Config.h"
#include "ConsoleLogger.h"
#include "ILogger.h"
#include "Paddle.h"



using std::make_shared;
using std::shared_ptr;
using std::unique_ptr;
using std::vector;


class Engine
{

private:
    Engine();

public:

    static Engine& getEngine();
    ~Engine();

    Config& getConfig() const;
    ILogger& getLogger() const;

    void init();
    void render() const; 
    void run();
    void update(float delta);
    
    void reset();

    void addGameObject(const shared_ptr<IGameObject>& gameObject);
    void addRenderable(const shared_ptr<const IRenderable>& renderable);
    void addCollider(const shared_ptr<BoxCollider>& collider);

    void initGameObjects();
    
private:
    unique_ptr<Config> config;
    unique_ptr<ILogger> logger;
    shared_ptr<sf::RenderWindow> renderWindow;
    sf::RenderTarget* renderTarget;

    // Should these really be smart pointers? (I think yes)
    vector<shared_ptr<IGameObject>> gameObjects;
    vector<shared_ptr<const IRenderable>> renderables;
    vector<shared_ptr<BoxCollider>> colliders;

    uint64_t frameCount;
};
