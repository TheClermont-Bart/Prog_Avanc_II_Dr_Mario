#include "Bullet.h"
#include "Engine.h"

void Bullet::Update(float deltaTime)
{
	m_rectX += m_rectSpeed * deltaTime;

	if (m_rectX > homer::Engine::Get()->WindowWidth() || m_rectX <= 0)
	{
		homer::Engine::Get()->World()->RemoveEntity(this);
	}

	if (m_rectY > homer::Engine::Get()->WindowHeight() || m_rectY <= 0)
	{
		homer::Engine::Get()->World()->RemoveEntity(this);
	}
}

void Bullet::Draw()
{
	homer::Engine::Get()->Gfx()->FillRect(m_rectX, m_rectY, 10, 10, Color(255, 255, 0, 255));
}
