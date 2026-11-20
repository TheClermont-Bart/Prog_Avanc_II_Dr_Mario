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
	/// <summary>
	/// Adds an animation clip to the animation component. The clip is defined by its name, the starting frame index, the number of frames in the clip, and the delay between frames.
	/// </summary>
	/// <param name="name"></param>
	/// <param name="start"></param>
	/// <param name="count"></param>
	/// <param name="delay"></param>
	void AddClip(const std::string& name, int start, int count, float delay);
	void Stop();
	/// <summary>
	/// Plays an animation clip by its name. If the loop parameter is set to true, the animation will loop indefinitely. If false, it will play once and stop at the last frame.
	/// </summary>
	/// <param name="name"></param>
	/// <param name="loop"></param>
	void Play(const std::string& name, bool loop);
	void Update(float deltaTime) override;
	/// <summary>
	/// Sets the current frame of the animation to the specified index. This allows for manual control of the animation frame, which can be useful for certain gameplay mechanics or effects.
	/// </summary>
	/// <param name="index"></param>
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