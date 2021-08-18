#include <cassert>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window.hpp>

#include "Ball.h"
#include "Debug.h"
#include "Engine.h"
#include "Field.h"
#include "Paddle.h"


using std::make_unique;
using sf::Keyboard;


Engine& Engine::getEngine()
{
    static Engine singleton;
    return singleton;
}

Engine::Engine() :
    renderTarget(nullptr),
    frameCount(0)
{
  init();
}

Engine::~Engine()
{
    if (renderTarget)
        renderTarget = nullptr;
}

Config& Engine::getConfig() const
{
    return *config;
}

ILogger& Engine::getLogger() const
{
    return *logger;
}

void Engine::init()
{
    this->logger = make_unique<ConsoleLogger>();
    this->config = make_unique<Config>();

    uint32_t style = sf::Style::Titlebar | sf::Style::Close;
    renderWindow = make_shared<sf::RenderWindow>(sf::VideoMode(800,600), "frack", style);
    renderTarget = &(*renderWindow); // address-of dereference due to shared_ptr

    renderWindow->setVerticalSyncEnabled(true);
    
    reset();
}

void Engine::reset()
{
    gameObjects.clear();
    renderables.clear();
    colliders.clear();
    initGameObjects();
}

void Engine::render() const
{
    renderWindow->clear();
    for (auto& renderable : renderables) {
        renderable->render(renderTarget);
    }
    renderWindow->display();
}

void Engine::run()
{
    sf::Clock clock;
    while (renderWindow->isOpen()) {
        clock.restart();
        ++frameCount;

        sf::Event event;
        while (renderWindow->pollEvent(event)) {
            if (event.key.code == Keyboard::Key::Escape ||
                event.type == sf::Event::Closed) {
                renderWindow->close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == Keyboard::Key::F5) {
                    getConfig().refresh();
                    reset();
                }
            }
        }

        update(clock.getElapsedTime().asSeconds());

        render();
    }
}

void Engine::update(float delta)
{
    // Check collisions
    for (uint32_t iter = 0; iter < colliders.size(); ++iter) {
        for (uint32_t remaining = iter+1; remaining < colliders.size(); ++remaining) {
            colliders[iter]->checkCollision(*(colliders[remaining]));
        }
    }

    // Update all game objects
    for (auto& gameObject : gameObjects) {
        gameObject->update(delta);
    }
}

void Engine::addGameObject(const shared_ptr<IGameObject>& gameObject)
{
    gameObjects.push_back(gameObject);
}

void Engine::addCollider(const shared_ptr<BoxCollider>& collider)
{
    colliders.push_back(collider);
}

/** Add IRenderable to renderables container */
void Engine::addRenderable(const shared_ptr<const IRenderable>& renderable)
{
    renderables.push_back(renderable);
}

void Engine::initGameObjects()
{

    auto playerPaddle = make_shared<Paddle>();
    playerPaddle->getTransform().setPosition({20, 10});
    addGameObject(playerPaddle); 
    addRenderable(playerPaddle); 

    auto aiPaddle = make_shared<Paddle>();
    uint32_t aiX = renderTarget->getSize().x - aiPaddle->getBounds().X() - 20;
    aiPaddle->getTransform().setPosition({static_cast<float>(aiX), 10});
    addGameObject(aiPaddle); 
    addRenderable(aiPaddle); 

    auto ball = make_shared<Ball>();
    ball->getTransform().setPosition({400, 300});
    addGameObject(ball);
    addRenderable(ball);

    auto field = make_shared<Field>(Vector2f(700.0f, 500.0f));
    field->getTransform().setPosition({100, 100});
    addGameObject(field);
    addRenderable(field);
}
