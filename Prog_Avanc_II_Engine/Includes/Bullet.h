#pragma once
#include "Entity.h"

class Bullet : public homer::Entity
{
public:
	Bullet(float x, float y, float speed) : Entity("Bullet")
	{
		m_rectX = x;
		m_rectY = y;
		m_rectSpeed = speed;
	}
	void Update(float deltaTime) override;
	void Draw() override;
private:
	float m_rectX;
	float m_rectY;
	float m_rectSpeed;
};