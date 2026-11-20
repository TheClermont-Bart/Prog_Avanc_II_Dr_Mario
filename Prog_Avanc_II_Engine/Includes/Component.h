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
	/// <summary>
	/// Sets the entity that this component is attached to. This is usually called by the Entity class when a component is added to it.
	/// </summary>
	/// <param name="entity"></param>
	void SetEntity(homer::Entity* entity)
	{
		m_Entity = entity;
	}
	/// <summary>
	/// Gets the entity that this component is attached to. This is usually called by the Entity class when a component is added to it.
	/// </summary>
	/// <returns></returns>
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