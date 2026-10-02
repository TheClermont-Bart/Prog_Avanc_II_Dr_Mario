#pragma once
#include "ILogger.h"

class Console_Log final : public ILogger
{
public:
	Console_Log();
	virtual ~Console_Log();
	/// <summary>
	/// Permet de loger un message dans la console en debug et dans un fichier log.txt en release
	/// </summary>
	/// <param name="text"></param>
	virtual void Log(std::string text) override;
};