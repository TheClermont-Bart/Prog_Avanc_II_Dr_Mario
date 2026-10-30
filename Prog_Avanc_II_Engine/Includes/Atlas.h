#pragma once
#include "Sprite.h"


class Atlas: public Sprite
{
public:
	void AddFrame(const std::string& name, int x, int y, int w, int h);
	void SetFrame(const std::string& name);
private:
	std::unordered_map<std::string, RectI> m_sourceMap;
};