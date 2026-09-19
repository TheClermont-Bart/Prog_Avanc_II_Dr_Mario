#pragma once
#include <string>

class ILogger
{
public:
    virtual ~ILogger() = default;
    virtual void Log(std::string text) = 0;
};