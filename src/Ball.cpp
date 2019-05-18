#include <SFML/Graphics/CircleShape.hpp>

#include "Ball.h"
#include "Common.h"
#include "Engine.h"

using std::make_unique;

Ball::Ball() :
    color({1.0f, 1.0f, 1.0f, 1.0f}),
    radius(10.0f),
    speed(Engine::getEngine().getConfig().getFloat("ballSpeed")),
    collider(BoxCollider(*this, { radius*2, radius*2 }))
{
    init();
}

void Ball::setColor(const Color& color)
{
    this->color = color;
}

void Ball::init()
{
    Engine::getEngine().addCollider(make_shared<BoxCollider>(collider));
    float angle = random(360.0f);
    trajectory = {
        (float)(cos(degToRad(angle))),
        (float)(sin(degToRad(angle)))
    };
    trajectory.normalize();
    printf("trajectory: %s\n", trajectory.toString().c_str());
}

void Ball::update(float delta)
{
    //printf("trajectory: %s\n", trajectory.toString());
    Vector2f velocity = trajectory * speed;
    transform.translate(velocity * delta);
    //transform.translate(trajectory * (speed * delta));
}

void Ball::render(sf::RenderTarget* renderTarget) const
{
    sf::CircleShape sprite(radius); 
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
//    collider._draw_collider(renderTarget);
}

void Ball::notifyEvent(const IGameObject& source, unique_ptr<Event> event)
{
    switch (event->getType()) {
    case Event::EventType::Collision:
        onCollision(source);
        break;
    }
}

void Ball::onCollision(const IGameObject& other)
{
    // mirror ball trajectory, then add some english
    trajectory = -trajectory;

    
}
