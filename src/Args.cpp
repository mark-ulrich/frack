#include <cstring>
#include <cstdio>

#include "Args.h"


Args::Args(int argc, const char **argv)
{
    this->argc = argc;
    this->argv = argv;
}

uint32_t Args::getArgCount() const
{
    return this->argc;
}

const char *Args::getArg(uint32_t index) const
{
    return this->argv[index];
}

int32_t Args::hasParm(const char *parm) const
{
    const char** curParm = (this->argv);
    for (uint32_t i = 0; i < this->argc; ++i, ++curParm) {
        if (strncmp(parm, *curParm, strlen(*curParm)) == 0) {
            return i;
        }
    }

    // parm not found
    return -1;
}
