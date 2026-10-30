#pragma once

namespace homer {
	class Entity;
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
	virtual void Start() {}
	virtual void Destroy() {}
protected:
	homer::Entity* m_Entity = nullptr;
};