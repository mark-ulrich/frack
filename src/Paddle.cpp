#include <cstdio>

#include <SFML/System/Clock.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "Engine.h"
#include "Paddle.h"


Paddle::Paddle() :
        bounds({(float)Engine::getEngine().getConfig().getInt("paddleWidth"),
                (float)Engine::getEngine().getConfig().getInt("paddleHeight")}),
        color(1.0f, 1.0f, 1.0f, 1.0f),
        collider(BoxCollider(*this, bounds))
{
    init();
} 

//Paddle::~Paddle() { }

/** * Get bounds of paddle as a Vector2 where x = width and y = height
 */
const Vector2f& Paddle::getBounds() const
{
    return bounds;
}

/**
 * Get color of paddle 
 */
const Color& Paddle::getColor() const
{
    return color;
}

/**
 * Render the paddle to a given RenderTarget
 */
void Paddle::render(sf::RenderTarget* renderTarget) const
{
    // TODO: Work in progress
    sf::RectangleShape sprite;
    sprite.setSize(sf::Vector2f(bounds.X(), bounds.Y()));
    sf::Vector2f position = {
        transform.getPosition().X(),
        transform.getPosition().Y()
    };
    sprite.setPosition(position);
    sprite.setFillColor(sf::Color(color.getRed(),
                                  color.getBlue(),
                                  color.getGreen(),
                                  color.getAlpha()));
    renderTarget->draw(sprite);
}

/** Set Paddle color */
void Paddle::setColor(const Color& color)
{
    this->color = color;
}

void Paddle::init()
{
    Engine::getEngine().addCollider(make_shared<BoxCollider>(collider));
}

void Paddle::update(float delta)
{
    using sf::Keyboard;

    // TODO: Separate paddle logic (Human/AI)
    // TODO: Implement config system
    const float PaddleSpeed = Engine::getEngine().getConfig().getFloat("paddleSpeed");
    //printf("paddleSpeed: %f <%u>\n", PaddleSpeed, (uint32_t)PaddleSpeed);
    
    if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
        getTransform().translate({0, -(PaddleSpeed * delta)});
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
        getTransform().translate({0, (PaddleSpeed * delta)});
    }        
}
