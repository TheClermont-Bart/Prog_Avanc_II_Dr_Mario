#include "Sprite.h"
#include "Engine.h"

void Sprite::Load(const std::string& textureName)
{
    m_TextureId = homer::Engine::Get()->Gfx()->LoadTexture(textureName);

    int w = 0;
    int h = 0;
    homer::Engine::Get()->Gfx()->GetTexture(m_TextureId, &w, &h);
    m_rect = { 0, 0, w, h };
}

void Sprite::Draw() 
{
    RectF dst = {
    m_Entity->x,
    m_Entity->y,
    static_cast<float>(m_rect.w)*m_scale,
    static_cast<float>(m_rect.h)*m_scale
    };

    homer::Engine::Get()->Gfx()->DrawTexture(m_TextureId, m_rect, dst, 0.0, m_flip, Color(255, 255, 255, 255));

}
