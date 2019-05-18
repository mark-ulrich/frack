#include <SFML/Graphics/RectangleShape.hpp>

#include "Field.h"

void Field::init()
{
    // Init colliders
    //top = {*this, {size.X(), }
}

void Field::update(float delta)
{
}

void Field::render(sf::RenderTarget* renderTarget) const
{
    sf::RectangleShape rect;
    rect.setSize({size.X(), size.Y()});
    rect.setFillColor({0, 0, 0, 0});
    rect.setOutlineColor({1, 1, 1, 1});
    rect.setOutlineThickness(10.0f);
    renderTarget->draw(rect);
}
