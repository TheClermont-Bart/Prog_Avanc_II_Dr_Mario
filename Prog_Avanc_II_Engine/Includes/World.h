#pragma once
#include "IWorld.h"
#include <vector>
#include <map>

namespace homer
{
	class World final : public IWorld
	{
	public:
		virtual ~World();
		virtual void AddEntity(Entity* entity) override;
		virtual void RemoveEntity(Entity* entity) override;
		virtual Entity* FindEntity(const char* name) override;
		virtual void Register(const std::string& name, IScene* scene) override;
		virtual void Load(const std::string& scene) override;
		virtual void Update(float deltaTime) override;
		virtual void Draw() override;
	private:
		void Unload();
		std::vector<Entity*> m_entityInWorld;
		std::map<std::string, Entity*> m_entityMap;
		std::vector<Entity*> m_toRemove;
		std::map<std::string, IScene*> m_scenes;
		IScene* m_currentScene = nullptr;
		std::string m_nextScene;
	};
}
