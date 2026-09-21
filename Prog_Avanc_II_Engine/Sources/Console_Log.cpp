#include "SDL.h"
#include "Console_Log.h"
#include <Windows.h>
#include <iostream>

Console_Log::Console_Log()
{
	AllocConsole();
	int _r = freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);
}

Console_Log::~Console_Log()
{
	FreeConsole();
}

void Console_Log::Log(std::string text)
{
	std::cout << "Message : " << text << std::endl;
}