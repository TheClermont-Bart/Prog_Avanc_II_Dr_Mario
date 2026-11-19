#pragma once
#include "Component.h"
#include "IGfx.h"

class Collider : public Component
{
public:
	Collider() = default;
	~Collider() override = default;

	void SetSize(float width, float height) { m_width = width; m_height = height; }
	
	RectF GetBounds();

	void Start() override;
	void Destroy() override;
private:
	float m_width = 0.0f;
	float m_height = 0.0f;
};