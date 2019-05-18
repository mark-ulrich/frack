#include "Util.h"

float clampValue(float value, float min, float max)
{
    float clampedValue;
    clampedValue = std::min(value, max);
    clampedValue = std::max(value, min);
    return clampedValue;
}
