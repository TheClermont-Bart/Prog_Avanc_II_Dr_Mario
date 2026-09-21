#pragma once
#include "ILogger.h"
#include <fstream>

class File_Log final : public ILogger
{
public:
	File_Log();
	virtual ~File_Log();
	virtual void Log(std::string text) override;
	std::ofstream MyFile;
};