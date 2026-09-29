#include "SdlSfx.h"

size_t SdlSfx::LoadMusic(const std::string& filename)
{
    const size_t _musicId = std::hash<std::string>()(filename);

    if (m_soundCache.find(_musicId) != m_soundCache.end())
    {
        return _musicId;
    }

    char* base = SDL_GetBasePath();
    const char* path = filename.c_str();

    std::string fullPath = std::string(base) + filename;
    SDL_free(base);

    Mix_Music* sample = Mix_LoadMUS(fullPath.c_str());

    if (sample != nullptr)
    {
        m_musicCache[_musicId] = sample;
        return _musicId;
    }

    return size_t();
}

size_t SdlSfx::LoadSound(const std::string& filename)
{
    const size_t _audioId = std::hash<std::string>()(filename);

    if (m_soundCache.find(_audioId) != m_soundCache.end())
    {
        return _audioId;
    }

    char* base = SDL_GetBasePath();
    const char* path = filename.c_str();

    std::string fullPath = std::string(base) + filename;
    SDL_free(base);

    Mix_Chunk* sample = Mix_LoadWAV(fullPath.c_str());

    if (sample != nullptr)
    {
        m_soundCache[_audioId] = sample;
        return _audioId;
    }

    return size_t();
}

void SdlSfx::PlayMusic(size_t id)
{
    Mix_PlayMusic(m_musicCache[id], 0);
}

void SdlSfx::PlayMusic(size_t id, int loop)
{
    Mix_PlayMusic(m_musicCache[id], loop);
}

void SdlSfx::PlaySFX(size_t id)
{
    Mix_PlayChannel(-1,m_soundCache[id],0);
}

void SdlSfx::PlaySFX(size_t id, int loop)
{
    Mix_PlayChannel(-1, m_soundCache[id], loop);
}

void SdlSfx::PauseMusic()
{
    Mix_Pause(-1);
}

void SdlSfx::StopMusic()
{
    Mix_Pause(-1);
    Mix_RewindMusic();
}

void SdlSfx::ResumeMusic()
{
    Mix_Resume(-1);
}

void SdlSfx::SetVolume(int volume)
{
    Mix_Volume(-1, volume);
}

void SdlSfx::SetVolume(size_t soundId, int volume)
{
    Mix_VolumeChunk(m_soundCache[soundId], volume);
}
