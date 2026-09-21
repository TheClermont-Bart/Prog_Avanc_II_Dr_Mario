#include "SDL.h"
#include "File_Log.h"
#include <iostream>


File_Log::File_Log()
{
	MyFile.open("log.txt");
}

File_Log::~File_Log()
{
	MyFile.close();
}

void File_Log::Log(std::string text)
{
	MyFile << "Message : " << text << std::endl;
}