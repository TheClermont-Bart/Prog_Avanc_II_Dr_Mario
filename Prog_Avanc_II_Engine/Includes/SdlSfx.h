#pragma once
#include "ISfx.h"

class SdlSfx final : public ISfx
{
public:
	SdlSfx() { Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024); };
	virtual ~SdlSfx() { Mix_CloseAudio(); };
	virtual size_t LoadMusic(const std::string& filename) override;
	virtual size_t LoadSound(const std::string& filename) override;
	virtual void PlayMusic(size_t id) override;
	virtual void PlayMusic(size_t id, int loop) override;
	virtual void PlaySFX(size_t id) override;
	virtual void PlaySFX(size_t id, int loop) override;
	virtual void PauseMusic() override;
	virtual void StopMusic() override;
	virtual void ResumeMusic() override;
	virtual void SetVolume(int volume) override;
	virtual void SetVolume(size_t soundId, int volume) override;
};