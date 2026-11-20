#include "Animation.h"

void Animation::InitAnimation(int frameInRows, int frameWidth, int frameHeight)
{
	m_frameInRows = frameInRows;
	m_frameWidth = frameWidth;
	m_frameHeight = frameHeight;
}

void Animation::AddClip(const std::string& name, int start, int count, float delay)
{
	m_sourceMap.emplace(name, anim{ start, count, delay });
}

void Animation::Stop()
{
    m_isPlaying = false;
}

void Animation::Play(const std::string& name, bool loop)
{
    auto it = m_sourceMap.find(name);

    if (it == m_sourceMap.end())
    {
        return;
    }

    m_currentClip = name;
    m_loop = loop;
    m_isPlaying = true;
    m_currentFrame = 0;
    m_timer = 0.0f;
    SetFrame(it->second.start);
}

void Animation::Update(float deltaTime)
{
    if(!m_isPlaying)
    {
        return;
    }

    auto it = m_sourceMap.find(m_currentClip);

    if (it == m_sourceMap.end())
    {
        return;
    }

    const anim& clip = it->second;
    m_timer += deltaTime;

    if(m_timer >= clip.delay)
    {
        m_timer = 0.0f;
        m_currentFrame++;

        if(m_currentFrame >= clip.count)
        {
            if (m_loop) 
            {
                m_currentFrame = 0;
            }
            else 
            {
                m_currentFrame = clip.count - 1;
                m_isPlaying = false;
            }
        }
        SetFrame(clip.start + m_currentFrame);
    }
}

void Animation::SetFrame(int index)
{
    int col = index % m_frameInRows;
    int row = index / m_frameInRows;

    m_rect = {
        col * m_frameWidth,
        row * m_frameHeight,
        m_frameWidth,
        m_frameHeight
    };
}
