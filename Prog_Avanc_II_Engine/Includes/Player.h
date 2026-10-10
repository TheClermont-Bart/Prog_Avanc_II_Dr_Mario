#pragma once
#include "Entity.h"

class Player : public homer::Entity
{
public:
	Player(float x, float y, float speed) : Entity("Player")
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
	bool m_shoot = false;
};