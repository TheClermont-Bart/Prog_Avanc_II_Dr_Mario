#pragma once
#include "Entity.h"
#include "IScene.h"


namespace homer
{
	class IWorld
	{
	public:
		virtual ~IWorld() = default;
		virtual void AddEntity(Entity* entity) = 0;
		virtual void RemoveEntity(Entity* entity) = 0;
		virtual Entity* FindEntity(const char* name) = 0;
		virtual void Register(const std::string& name, IScene* scene) = 0;
		virtual void Load(const std::string& scene) = 0;
		virtual void Update(float deltaTime) = 0;
		virtual void Draw() = 0;
	};
}
