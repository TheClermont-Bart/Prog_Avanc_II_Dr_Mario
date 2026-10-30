#include "Controller.h"
#include "Entity.h"
#include "Engine.h"

Controller::Controller()	
{

}

void Controller::Update(float deltaTime)
{
	float speed = 200.0f;
	homer::Engine* eng = homer::Engine::Get();

	if (eng->Input()->IsKeyDown(static_cast<int>(EKey::EKEY_A)))
	{
		m_Entity->x -= speed * deltaTime;
	}

	if (eng->Input()->IsKeyDown(static_cast<int>(EKey::EKEY_D)))
	{
		m_Entity->x += speed * deltaTime;
	}

	if (eng->Input()->IsKeyDown(static_cast<int>(EKey::EKEY_W)))
	{
		m_Entity->y -= speed * deltaTime;
	}

	if (eng->Input()->IsKeyDown(static_cast<int>(EKey::EKEY_S)))
	{
		m_Entity->y += speed * deltaTime;
	}
}
