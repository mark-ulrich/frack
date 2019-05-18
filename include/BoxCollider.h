#pragma once

#include <SFML/Graphics/RenderTarget.hpp>

#include "GameObject.h"
#include "Vector2.h"


class BoxCollider
{
public:

    struct Box
    {
        float left,top,right,bottom;
    };

    BoxCollider(GameObject& master, const Vector2f& bounds);
    ~BoxCollider();

//    void update(float delta);
    
    void checkCollision(BoxCollider& other) const;
    void notifyCollision(GameObject& other) const;

    const GameObject& getMaster() const;

    void _draw_collider(sf::RenderTarget* renderTarget) const;

private:
    GameObject& master;
    const Vector2f bounds;
};
