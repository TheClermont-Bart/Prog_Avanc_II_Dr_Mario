#include "SDL.h"
#include "File_Log.h"
#include <iostream>


File_Log::File_Log()
{
	m_fileLog.open("log.txt");
}

File_Log::~File_Log()
{
	m_fileLog.close();
}

void File_Log::Log(std::string text)
{
	m_fileLog << "Message : " << text << std::endl;
}