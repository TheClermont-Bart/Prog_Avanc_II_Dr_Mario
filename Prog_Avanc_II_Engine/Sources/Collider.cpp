#include "Collider.h"
#include "Entity.h"
#include "ICollision.h"

RectF Collider::GetBounds()
{
	return RectF{m_Entity->x, m_Entity->y, m_width, m_height};
}

void Collider::Start()
{
	Collision()->Subscribe(this);
}

void Collider::Destroy()
{
	Collision()->Unsubscribe(this);
}
