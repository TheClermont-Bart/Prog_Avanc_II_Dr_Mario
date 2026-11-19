#pragma once

class IInput;
class IGfx;

namespace homer {
	class Entity;
	class IWorld;
	class ICollision;
}

class Component 
{
public:
	virtual ~Component() = default;
	Component() = default;
	Component(homer::Entity* parent) : m_Entity(parent) {}

	void SetEntity(homer::Entity* entity)
	{
		m_Entity = entity;
	}
	homer::Entity* GetEntity() { return m_Entity; }
	virtual void Start() {}
	virtual void Destroy() {}
protected:
	homer::Entity* m_Entity = nullptr;
	homer::IWorld* World();
	homer::ICollision* Collision();
	IInput* Input();
	IGfx* Gfx();
};