#pragma once

class Event
{
public:
    enum EventType {
        Collision
    };

    Event(EventType type) : type(type) {}
    virtual EventType getType() const { return type; }

private:
    EventType type;
};
