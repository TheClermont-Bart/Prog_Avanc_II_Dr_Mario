#include "Atlas.h"

void Atlas::AddFrame(const std::string& name, int x, int y, int w, int h)
{
	m_sourceMap.emplace(name, RectI{ x, y, w, h });
}

void Atlas::SetFrame(const std::string& name)
{
	auto rect = m_sourceMap.find(name);
	
	if(rect == m_sourceMap.end())
	{
		return;
	}

	m_rect = rect->second;
}
