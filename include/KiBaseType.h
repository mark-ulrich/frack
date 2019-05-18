#pragma once

#include <string>


/** The base class to *every* class in KiEngine. Akin to Java's 'Object' class */
class KiBaseType
{
public:
    virtual std::string toString() const = 0;
};
