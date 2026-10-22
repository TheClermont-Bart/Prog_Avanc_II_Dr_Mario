#include "Scene0.h"
#include "Engine.h"
#include "Square.h"

void Scene0::Load()
{
	homer::Engine* eng = homer::Engine::Get();

	m_background = eng->Get()->Gfx()->LoadTexture("standby.jpg");
	eng->Get()->Gfx()->DrawTexture(m_background, {255,255,255,255});

	eng->World()->AddEntity("Scene0")->AddComponent(new Square());


}

void Scene0::Update(float deltatime)
{
	homer::Engine* eng = homer::Engine::Get();

	if (eng->Input()->IsKeyDown(static_cast<int>(EKey::EKEY_RETURN)))
	{
		eng->World()->Load("Scene1");
	}
}

void Scene0::Draw()
{
	homer::Engine* eng = homer::Engine::Get();
	eng->Get()->Gfx()->DrawTexture(m_background, { 255,255,255,255 });
}

void Scene0::Unload()
{

}
