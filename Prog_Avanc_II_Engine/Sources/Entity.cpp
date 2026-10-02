#include "Entity.h"

void Entity::Start() 
{

}

void Entity::Update(float deltaTime) 
{

}

void Entity::Draw()
{
	for (auto entity : m_EntityInWorld)
	{
		entity->Draw();
	}
}

void Entity::Destroy() 
{

}