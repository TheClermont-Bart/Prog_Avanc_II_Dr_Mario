#pragma once
#include <string>
#include "Component.h"
#include "IUpdateable.h"
#include "IDrawable.h"
#include <unordered_map>

struct anim {
	int start;
	int count;
	float delay;
};

class Animation: public Component, public IUpdateable, public IDrawable
{
public:
	void InitAnimation(int frameInRows, int frameWidth, int frameHeight);
	void AddClip(const std::string& name, int start, int count, float delay);
	void Stop();
	void Play(const std::string& name, bool loop);
private:
	std::unordered_map<std::string, anim> m_sourceMap;
};