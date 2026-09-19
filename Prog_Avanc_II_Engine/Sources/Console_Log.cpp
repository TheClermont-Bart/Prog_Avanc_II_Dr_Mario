#include "SDL.h"
#include "Console_Log.h"
#include <Windows.h>
#include <iostream>
#include "SdlInput.h"

Console_Log::Console_Log()
{
	AllocConsole();
}

Console_Log::~Console_Log()
{
	FreeConsole();
}

void Console_Log::Log(std::string text)
{
	int _r = freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 12); 
	std::cout << "Touche : " << text << std::endl;

}