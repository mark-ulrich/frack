#pragma once

#include <cstdio>
#include <iostream>

#include "ILogger.h"

class ConsoleLogger :
    public ILogger
{
    static constexpr std::ostream& DefaultLogStream = std::cout;

public:
    ConsoleLogger();
    ConsoleLogger(std::ostream& logStream);

    void log(const std::string& logMessage);

private:
    std::ostream& logStream;
};
