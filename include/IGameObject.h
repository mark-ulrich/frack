#pragma once

#include <memory>

#include "Event.h"
#include "Transform.h"


class IGameObject {
public:
    virtual void init() = 0;
    virtual void update(float delta) = 0;

    // Events
    virtual void notifyEvent(const IGameObject& source, std::unique_ptr<Event> event) = 0;

    virtual Transform& getTransform() = 0;
    virtual const Transform& getTransform() const = 0;
};
