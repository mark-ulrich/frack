#pragma once

#include <SFML/Graphics/RenderTarget.hpp>


class IRenderable {
public:
    virtual void render(sf::RenderTarget* renderTarget) const = 0;
};
