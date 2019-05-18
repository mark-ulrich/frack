#pragma once

#include <cstdint>
#include <memory>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "BoxCollider.h"
#include "Color.h"
#include "GameObject.h"
#include "IRenderable.h"
#include "Vector2.h"


using std::make_shared;
using std::shared_ptr;


/**
 * Paddle class
 */
class Paddle :
    public GameObject,
    public IRenderable
{
public:
    Paddle();
    //~Paddle();

    const Vector2f& getBounds()   const;
    const Color&    getColor()    const;
    void setColor(const Color& color);
    
    std::string toString() const { return "Paddle"; }

    // IGameObject
    void init();
    void update(float delta);
    void notifyEvent(const IGameObject& source, const std::unique_ptr<Event> event){}

    // IRenderable
    void render(sf::RenderTarget* renderTarget) const;
    
private:
    Vector2f bounds;
    Color    color;
    BoxCollider collider;

};
