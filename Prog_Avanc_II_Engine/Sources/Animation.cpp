#include "Animation.h"

void Animation::InitAnimation(int frameInRows, int frameWidth, int frameHeight)
{
}

void Animation::AddClip(const std::string& name, int start, int count, float delay)
{
	m_sourceMap.emplace(name, (start, count, delay));
}

void Animation::Stop()
{
}

void Animation::Play(const std::string& name, bool loop)
{
}
