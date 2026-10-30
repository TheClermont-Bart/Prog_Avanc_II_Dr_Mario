#pragma once
#include "Component.h"
#include "IDrawable.h"
#include "IGfx.h"

class Sprite : public Component, public IDrawable
{
public:
	Sprite() = default;
	~Sprite() = default;

	void Load(const std::string& textureName);
	virtual void Draw() override;
	void SetScale(float scale) { m_scale = scale; };
protected:
	RectI m_rect{};
private:
	size_t m_TextureId = 0;
	Flip m_flip{};
	float m_scale = 1.0f;
};