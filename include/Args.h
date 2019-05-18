#include <cstdint>

class Args {
public:
    Args(int argc, const char **argv);

    int32_t     hasParm(const char*) const;
    const char* getArg(uint32_t)     const;
    uint32_t    getArgCount()        const;

private:
    const char** argv;
    uint32_t     argc;
};

