#include "Atlas.h"

void Atlas::AddFrame(const std::string& name, int x, int y, int w, int h)
{
	m_sourceMap.emplace(name, (x, y, w, h));
}

void Atlas::SetFrame(const std::string& name)
{
	int h = m_sourceMap.find(name)->second.h;
	int w = m_sourceMap.find(name)->second.w;
	int x = m_sourceMap.find(name)->second.x;
	int y = m_sourceMap.find(name)->second.y;

	m_rect.h = h;
	m_rect.w = w;
	m_rect.y = y;
	m_rect.x = x;

	Load(name);
}
