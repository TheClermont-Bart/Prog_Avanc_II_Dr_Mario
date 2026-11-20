#pragma once
#include "Component.h"
#include "IDrawable.h"
#include "IUpdateable.h"

class Bullet : public Component, public IDrawable, public IUpdateable
{
public:
	Bullet() = default;
	void Update(float deltaTime) override;
	void Draw() override;
	void SetSpeed(float speed) { m_rectSpeed = speed; }	
private:
	float m_rectX;
	float m_rectY;
	float m_rectSpeed;
};