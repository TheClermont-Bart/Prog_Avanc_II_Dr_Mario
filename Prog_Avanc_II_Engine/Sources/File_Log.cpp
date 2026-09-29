#include "SDL.h"
#include "File_Log.h"
#include <iostream>


File_Log::File_Log()
{
	fileLog.open("log.txt");
}

File_Log::~File_Log()
{
	fileLog.close();
}

void File_Log::Log(std::string text)
{
	fileLog << "Message : " << text << std::endl;
}