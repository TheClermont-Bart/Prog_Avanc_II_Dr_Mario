#pragma once
#include "Entity.h"


class Component 
{
public:
	virtual ~Component() = default;
	Component();
	Component(homer::Entity* parent);


	virtual void Start() {}
	virtual void Destroy() {}
protected:
	homer::Entity* m_Entity = nullptr;
};