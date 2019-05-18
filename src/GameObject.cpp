#include "GameObject.h"

Transform& GameObject::getTransform() 
{
    return transform;
}

const Transform& GameObject::getTransform() const
{
    return transform;
}

