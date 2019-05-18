#pragma once

#include <cstdint>


class Color {
public:
    Color() : Color(0.0f, 0.0f, 0.0f, 0.0f) {}
    Color(float r, float g, float b, float a);

    uint8_t getRed()   const;
    uint8_t getGreen() const;
    uint8_t getBlue()  const;
    uint8_t getAlpha() const;

private:
    uint8_t r,g,b,a;

};
