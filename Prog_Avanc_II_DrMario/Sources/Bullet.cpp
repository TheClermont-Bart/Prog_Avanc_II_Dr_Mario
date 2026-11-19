#include "Bullet.h"
#include "Engine.h"
#include "Collider.h"

void Bullet::Update(float deltaTime)
{
	m_Entity->x += m_rectSpeed * deltaTime;

	if (m_Entity->x > homer::Engine::Get()->WindowWidth() || m_Entity->x <= 0)
	{
		World()->RemoveEntity(m_Entity);
	}

	if (m_Entity->y > homer::Engine::Get()->WindowHeight() || m_Entity->y <= 0)
	{
		World()->RemoveEntity(m_Entity);
	}

	Collider* self = m_Entity->GetComponent<Collider>();
	if (self != nullptr)
	{
		Collider* hit = Collision()->CheckCollisions(self);
		if (hit != nullptr)
		{
			World()->RemoveEntity(hit->GetEntity());
			World()->RemoveEntity(m_Entity);
			return;
		}
	}
}

void Bullet::Draw()
{
	Gfx()->FillRect(m_Entity->x, m_Entity->y, 10, 10, Color(255, 255, 0, 255));
}
