#pragma once

#include "BoxCollider.h"
#include "Color.h"
#include "GameObject.h"
#include "IRenderable.h"
#include "Transform.h"

class Ball :
    public GameObject,
    public IRenderable
{
public:
    Ball();

    void setColor(const Color& color);

    void init();
    void update(float delta);
    void notifyEvent(const IGameObject& source, std::unique_ptr<Event> event);

    void render(sf::RenderTarget* renderTarget) const;

    void onCollision(const IGameObject& other);

    std::string toString() const { return "Ball"; }

private:
    Color color;
    float radius;
    float speed;
    Vector2f trajectory;

    BoxCollider collider;
};
