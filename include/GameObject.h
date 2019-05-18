#pragma once

#include "Common.h"
#include "IGameObject.h"

/**
 * Base GameObject class. Implements generic IGameObject interface methods.
 *
 * This class is abstract and cannot be instantiated.
 */
class GameObject :
    public IGameObject
{
public:
    Transform& getTransform();
    const Transform& getTransform() const;

    virtual std::string toString() const { NOTIMPL; }


protected:
    Transform transform;
};
