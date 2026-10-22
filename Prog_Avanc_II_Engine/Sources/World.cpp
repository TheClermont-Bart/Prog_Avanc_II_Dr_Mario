#include "World.h"

homer::World::~World()
{
	Unload();
	for (auto scene : m_scenes)
	{
		delete scene.second;
	}
	m_scenes.clear();
}

homer::Entity* homer::World::AddEntity(const std::string & name)
{
	Entity* entity = new Entity(name);
	m_entityInWorld.push_back(entity);
	return entity;
}

void homer::World::RemoveEntity(Entity* entity)
{
	m_toRemove.emplace_back(entity);
}

homer::Entity* homer::World::FindEntity(const char* name)
{
	if (m_entityMap.count(name) > 0)
	{
		return m_entityMap[name];
	}

	return nullptr;
}

void homer::World::Register(const std::string& name, IScene* scene)
{
	if(m_scenes.count(name) == 0)
	{
		m_scenes[name] = scene;
	}
}

void homer::World::Load(const std::string& scene)
{
	if(m_currentScene != nullptr)
	{
		m_currentScene->Unload();
	}	
	m_nextScene = scene;
}

void homer::World::Update(float deltaTime)
{
	if(m_currentScene)
	{
		m_currentScene->Update(deltaTime);
	}

	for (size_t i = 0; i < m_entityInWorld.size(); i++)
	{
		m_entityInWorld[i]->Update(deltaTime);
	}

	for (auto entity : m_toRemove)
	{
		auto it = std::find(m_entityInWorld.begin(), m_entityInWorld.end(), entity);

		if (it != m_entityInWorld.end())
		{
			m_entityInWorld.erase(it);
			m_entityMap.erase(entity->GetName());
			entity->Destroy();
			delete entity;
		}
	}

	m_toRemove.clear();
	if (m_scenes.count(m_nextScene) > 0)
	{
		Unload();
		m_currentScene = m_scenes[m_nextScene];
		m_currentScene->Load();
	}

	m_nextScene.clear();
}

void homer::World::Draw()
{
	if(m_currentScene)
	{
		m_currentScene->Draw();
	}

	for (auto entity : m_entityInWorld)
	{
		entity->Draw();
	}
}

void homer::World::Unload()
{
	for (auto entity : m_entityInWorld)
	{
		entity->Destroy();
		delete entity;
	}
	m_entityInWorld.clear();
	m_entityMap.clear();
	m_toRemove.clear();
	m_currentScene = nullptr;
}
