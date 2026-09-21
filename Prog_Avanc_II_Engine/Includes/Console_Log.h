#pragma once
#include "ILogger.h"

class Console_Log final : public ILogger
{
public:
	Console_Log();
	virtual ~Console_Log();
	virtual void Log(std::string text) override;
};