#include "Collision.h"
#include "Collider.h"

void homer::Collision::Subscribe(Collider* collider)
{
	if(collider == nullptr)
	{
		return;
	}	

	auto it = std::find(m_Colliders.begin(), m_Colliders.end(), collider);
	if(it != m_Colliders.end())
	{
		return;
	}

	m_Colliders.push_back(collider);
}

void homer::Collision::Unsubscribe(Collider* collider)
{
	if(collider == nullptr)
	{
		return;
	}

	auto it = std::find(m_Colliders.begin(), m_Colliders.end(), collider);
	if(it != m_Colliders.end())
	{
		m_Colliders.erase(it);
	}

}

Collider* homer::Collision::CheckCollisions(Collider* collider)
{
	if(collider == nullptr)
	{
		return nullptr;
	}

	RectF boundsA = collider->GetBounds();

	for(Collider* other : m_Colliders)
	{
		if(other == collider)
		{
			continue;
		}

		RectF boundsB = other->GetBounds();

		if(boundsA.x < boundsB.x + boundsB.w &&
		   boundsA.x + boundsA.w > boundsB.x &&
		   boundsA.y < boundsB.y + boundsB.h &&
		   boundsA.y + boundsA.h > boundsB.y)
		{
			return other;
		}
	}	

	return nullptr;
}
