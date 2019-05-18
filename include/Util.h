#pragma once

#include <cassert>
#include <cmath>
#include <cstdarg>
#include <ctime>

#include "Config.h"



#define DBG_MARK(X) \
{ \
    std::cout << "DEBUG MARKER: " << __FUNCTION__ << "\t\t---> [" << std::hex << (X) << "]\n" << std::dec; \
}
#define _D DBG_MARK

#define NOTIMPL \
{ \
    throw std::runtime_error(std::string(__FUNCTION__) + ": Not Implemented"); \
}



Config& getConfig();

float clampValue(float value, float min, float max);

inline std::string formatString(const char* fmt, ...)
{
    const size_t BUF_SIZE = 512;
    char buffer[BUF_SIZE];
    va_list args;
    va_start(args, fmt);
    vsprintf(buffer, fmt, args);
    perror(buffer);
    va_end(args);
    return std::string(buffer);
}

// TODO: make template
inline float random(float max)
{
    srand(time(NULL));
    float ret = static_cast<float>(rand() % static_cast<int>(max*1000)) / 1000;
    assert(ret < 360.0f);
    return ret; 
}

inline float degToRad(float deg)
{
    return deg * M_PI/180;
}
