#pragma once

#include <memory>

#include "BoxCollider.h"
#include "GameObject.h"
#include "IRenderable.h"
#include "Vector2.h"


class Field :
    public GameObject,
    public IRenderable
{
public: 
    Field(const Vector2f& size) : size(size) { init(); }

    void init();
    void update(float delta);

    void render(sf::RenderTarget* renderTarget) const;

    void notifyEvent(const IGameObject& source, std::unique_ptr<Event> event) {}

private:
    Vector2f size;
};
