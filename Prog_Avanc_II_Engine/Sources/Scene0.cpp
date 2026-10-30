#include "Scene0.h"
#include "Engine.h"
#include "Square.h"
#include "Sprite.h"
#include "Controller.h"

void Scene0::Load()
{
	homer::Engine* eng = homer::Engine::Get();
	homer::Entity* entity0 = eng->World()->AddEntity("Carrer0");
	homer::Entity* entity1 = eng->World()->AddEntity("Carrer1");

	m_background = eng->Get()->Gfx()->LoadTexture("standby.jpg");
	eng->Get()->Gfx()->DrawTexture(m_background, {255,255,255,255});

	Square* square0 = entity0->AddComponent<Square>();
	entity0->x = eng->WindowWidth() / 2.0f - 25.0f;
	entity0->y = eng->WindowHeight() / 2.0f - 25.0f;

	Sprite* sprite0 = entity1->AddComponent<Sprite>();
	sprite0->Load("mouche.png");
	sprite0->SetScale(0.1f);
	
	Controller* newController = entity0->AddComponent<Controller>();

	Square* checkSquare = entity0->GetComponent<Square>();
	if (square0 == checkSquare) {
		printf("Ca marche!");
	}
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
