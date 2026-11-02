#pragma once
#include <string>
#include "Atlas.h"
#include "IUpdateable.h"
#include <unordered_map>

struct anim {
	int start;
	int count;
	float delay;
};

class Animation: public Atlas, public IUpdateable
{
public:
	void InitAnimation(int frameInRows, int frameWidth, int frameHeight);
	void AddClip(const std::string& name, int start, int count, float delay);
	void Stop();
	void Play(const std::string& name, bool loop);
	void Update(float deltaTime) override;
	void SetFrame(int index);
private:
	std::unordered_map<std::string, anim> m_sourceMap;
	int m_frameInRows = 0;
	int m_frameWidth = 0;
	int m_frameHeight = 0;
	std::string m_currentClip;
	int m_currentFrame = 0;
	float m_timer = 0.0f;
	bool m_isPlaying = false;
	bool m_loop = false;
};