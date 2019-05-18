#pragma once

#include <cmath>

#include "Common.h"


template <typename T>
class Vector2 :
    public KiBaseType
{
public:
    static Vector2 normalize(const Vector2& in) 
    {
        return in/in.length();
    }

    Vector2() : Vector2(0, 0) {}
    Vector2(T x, T y) : x(x), y(y) {}

    // TODO: make x and y publically accessible
    T X() const { return x; }
    T Y() const { return y; }

    float length() const { return sqrt(x*x + y*y); }

    Vector2 normalize()
    {
        return normalize(*this);
    }

    std::string toString() const
    { 
        return formatString("[%f,%f]", x, y);
    }

    // Operators
    friend const Vector2<T> operator -(const Vector2<T>& vec)
    {
        return Vector2<T> { -vec.x, -vec.y };
    }

    friend const Vector2<T> operator +(const Vector2<T>& lhs, const Vector2<T>& rhs)
    {
        return {
            lhs.x + rhs.x,
            lhs.y + rhs.y
        };
    }

    friend Vector2<T>& operator +=(Vector2<T>& lhs, const Vector2<T>& rhs)
    {
        return lhs = lhs + rhs;
    }

    friend Vector2<T> operator *(const Vector2<T>& lhs, const Vector2<T>& rhs)
    {
        return {
            lhs.x * rhs.x,
            lhs.y * rhs.y
        };
    }

    friend Vector2<T>& operator *=(Vector2<T>& lhs, const Vector2<T>& rhs)
    {
        return lhs = lhs * rhs;
    }

    // multiply by scalar
    friend Vector2<T> operator *(const Vector2<T>& lhs, float scalar)
    {
        return {
            lhs.x * scalar,
            lhs.y * scalar
        };
    }

    friend Vector2<T> operator /(const Vector2<T>& lhs, float scalar)
    {
        return {
            lhs.x / scalar,
            lhs.y / scalar
        };
    }

private:
    T x, y;
};


using Vector2i = Vector2<int>;
using Vector2f = Vector2<float>;
