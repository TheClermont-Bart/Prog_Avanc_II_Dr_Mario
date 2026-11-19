#pragma once
#include "ICollision.h"
#include <vector>

namespace homer
{
	class Collision final : public ICollision
	{
	public:
		~Collision() override = default;

		void Subscribe(Collider* collider) override;
		void Unsubscribe(Collider* collider) override;
		Collider* CheckCollisions(Collider* collider) override;
	private:
		std::vector<Collider*> m_Colliders;
	};
}