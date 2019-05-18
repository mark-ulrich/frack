#include "ConsoleLogger.h"

ConsoleLogger::ConsoleLogger() :
    ConsoleLogger(DefaultLogStream) 
{ /* EMPTY */ }

ConsoleLogger::ConsoleLogger(std::ostream& logStream) :
    logStream(logStream)
{ /*EMPTY*/ }

void ConsoleLogger::log(const std::string& logMessage)
{
    logStream << logMessage << '\n';
}
