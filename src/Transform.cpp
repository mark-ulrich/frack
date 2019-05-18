#include "Transform.h"

Transform::Transform()
{/*EMPTY*/}

const Vector2f& Transform::getPosition() const
{
    return this->position;
}

const Vector2f& Transform::getRotation() const
{
    return this->rotation;
}

const Vector2f& Transform::getScale() const
{
    return this->scale;
}

void Transform::setPosition(const Vector2f& position)
{
    this->position = position;
}

void Transform::setRotation(const Vector2f& rotation)
{
    this->rotation = rotation;
}

void Transform::setScale(const Vector2f& scale)
{
    this->scale = scale;
}

void Transform::translate(const Vector2f& translation) 
{
    this->position += translation;
}
