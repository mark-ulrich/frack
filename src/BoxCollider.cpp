#include <cstdio>

#include <SFML/Graphics/RectangleShape.hpp>

#include "BoxCollider.h"

BoxCollider::BoxCollider(GameObject& master, const Vector2f& bounds) :
    master(master), bounds(bounds)
{
    // register with physics base
}

BoxCollider::~BoxCollider()
{
    // Unregister with physics base
}

void BoxCollider::_draw_collider(sf::RenderTarget* renderTarget) const
{
    sf::RectangleShape rect;
    
    rect.setSize(sf::Vector2f(bounds.X(), bounds.Y()));
    rect.setOutlineThickness(1.0f);
    rect.setOutlineColor(sf::Color(0xff, 0xff, 0xff, 0xff));
    rect.setFillColor(sf::Color(0x00, 0x00, 0x00, 0x00));
    rect.setPosition(sf::Vector2f(master.getTransform().getPosition().X(),
                                  master.getTransform().getPosition().Y()));
    renderTarget->draw(rect);
}

void BoxCollider::checkCollision(BoxCollider& other) const
{
    Box myBox = {
        .left   = master.getTransform().getPosition().X(),
        .top    = master.getTransform().getPosition().Y(),
        .right  = master.getTransform().getPosition().X() + bounds.X(),
        .bottom = master.getTransform().getPosition().Y() + bounds.Y()
    }; 

    Box otherBox = {
        .left   = other.getMaster().getTransform().getPosition().X(),
        .top    = other.getMaster().getTransform().getPosition().Y(),
        .right  = other.getMaster().getTransform().getPosition().X() + bounds.X(),
        .bottom = other.getMaster().getTransform().getPosition().Y() + bounds.Y()
    }; 
    
    if (myBox.left < otherBox.right &&
        myBox.right > otherBox.left &&
        myBox.top < otherBox.bottom &&
        myBox.bottom > otherBox.top)
    {
        //printf("collision!\n");
        notifyCollision(other.master);
    }
}

void BoxCollider::notifyCollision(GameObject& other) const
{
    using std::make_unique;
    master.notifyEvent(other, make_unique<Event>(Event::EventType::Collision));
    other.notifyEvent(master, make_unique<Event>(Event::EventType::Collision));
}

const GameObject& BoxCollider::getMaster() const
{
    return master;
}
