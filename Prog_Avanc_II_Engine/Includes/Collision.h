#pragma once
#include "ICollision.h"
#include <vector>

namespace homer
{
	class Collision final : public ICollision
	{
	public:
		~Collision() override = default;
		/// <summary>
		/// Subscribes a collider to the collision system, adding it to the list of colliders to be checked for collisions.
		/// </summary>
		/// <param name="collider"></param>
		void Subscribe(Collider* collider) override;
		/// <summary>
		/// Unsubscribes a collider from the collision system, removing it from the list of colliders to be checked for collisions.
		/// </summary>
		/// <param name="collider"></param>
		void Unsubscribe(Collider* collider) override;
		/// <summary>
		/// Checks for collisions between the provided collider and all other subscribed colliders. If a collision is detected, it returns the first collider that collides with the provided one; otherwise, it returns nullptr.
		/// </summary>
		/// <param name="collider"></param>
		/// <returns></returns>
		Collider* CheckCollisions(Collider* collider) override;
	private:
		std::vector<Collider*> m_Colliders;
	};
}