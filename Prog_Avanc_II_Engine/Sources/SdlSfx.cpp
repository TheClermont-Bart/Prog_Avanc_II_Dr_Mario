#include "SdlSfx.h"
#include "SDL_mixer.h"
#include "SDL.h"

SdlSfx::SdlSfx()
{
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    Mix_Init(MIX_INIT_MP3);
}

SdlSfx::~SdlSfx()
{
    for (auto& music : m_musicCache)
    {
        Mix_FreeMusic(music.second);
    }
    for (auto& sound : m_soundCache)
    {
        Mix_FreeChunk(sound.second);
    }
    Mix_CloseAudio();
}

size_t SdlSfx::LoadMusic(const std::string& filename)
{
    const size_t musicId = std::hash<std::string>()(filename);

    if (m_soundCache.find(musicId) != m_soundCache.end())
    {
        return musicId;
    }

    char* folder = "./assets/";

    std::string fullPath = std::string(folder) + filename;

    Mix_Music* sample = Mix_LoadMUS(fullPath.c_str());

    if (sample != nullptr)
    {
        m_musicCache[musicId] = sample;
        return musicId;
    }

    return size_t();
}

size_t SdlSfx::LoadSound(const std::string& filename)
{
    const size_t audioId = std::hash<std::string>()(filename);

    if (m_soundCache.find(audioId) != m_soundCache.end())
    {
        return audioId;
    }

    char* folder = "./assets/";

    std::string fullPath = std::string(folder) + filename;

    Mix_Chunk* sample = Mix_LoadWAV(fullPath.c_str());

    if (sample != nullptr)
    {
        m_soundCache[audioId] = sample;
        return audioId;
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
