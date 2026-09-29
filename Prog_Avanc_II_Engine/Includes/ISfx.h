#pragma once
#include <string>
#include "SDL_mixer.h"
#include "SDL.h"
#include <unordered_map>

class ISfx
{
public:
	virtual ~ISfx() = default;
	virtual size_t LoadMusic(const std::string& filename) = 0;
	virtual size_t LoadSound(const std::string& filename) = 0;
	virtual void PlayMusic(size_t id) = 0;
	virtual void PlayMusic(size_t id, int loop) = 0;
	virtual void PlaySFX(size_t id) = 0;
	virtual void PlaySFX(size_t id, int loop) = 0;
	virtual void PauseMusic() = 0;
	virtual void StopMusic() = 0;
	virtual void ResumeMusic() = 0;
	virtual void SetVolume(int volume) = 0;
	virtual void SetVolume(size_t soundId, int volume) = 0;
protected:
	std::unordered_map<size_t, Mix_Music*> m_musicCache;
	std::unordered_map<size_t, Mix_Chunk*> m_soundCache;
};