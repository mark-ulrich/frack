#pragma once

#include "Vector2.h"

class Transform
{
public:
    Transform();

    const Vector2f& getPosition() const;
    const Vector2f& getRotation() const;
    const Vector2f& getScale() const;

    void setPosition(const Vector2f& position);
    void setRotation(const Vector2f& rotation);
    void setScale(const Vector2f& scale);

    void translate(const Vector2f& translation);

private:
    Vector2f position;
    Vector2f rotation;
    Vector2f scale;
};
