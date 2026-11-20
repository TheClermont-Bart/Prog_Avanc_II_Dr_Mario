#pragma once

class Collider;

namespace homer
{

class ICollision
{
public:
	virtual ~ICollision() = default;
	virtual void Subscribe(Collider* collider) = 0;
	virtual void Unsubscribe(Collider* collider) = 0;
	virtual Collider* CheckCollisions(Collider* collider) = 0;
};
}