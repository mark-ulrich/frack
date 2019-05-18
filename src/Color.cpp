#include <algorithm>

#include "Color.h"
#include "Util.h"


Color::Color(float r, float g, float b, float a)
{
    r = clampValue(r, 0.0f, 1.0f);
    g = clampValue(g, 0.0f, 1.0f);
    b = clampValue(b, 0.0f, 1.0f);
    a = clampValue(a, 0.0f, 1.0f);
    this->r = (uint8_t)(r * 255.0);
    this->g = (uint8_t)(g * 255.0);
    this->b = (uint8_t)(r * 255.0);
    this->a = (uint8_t)(a * 255.0);
}

uint8_t Color::getRed() const
{
    return r;
}

uint8_t Color::getGreen() const
{
    return g;
}

uint8_t Color::getBlue() const
{
    return b;
}

uint8_t Color::getAlpha() const
{
    return a;
}

