#include "Scene0.h"
#include "Engine.h"
#include "Square.h"
#include "Sprite.h"
#include "Controller.h"
#include "Atlas.h"
#include "Animation.h"

void Scene0::Load()
{
	homer::Engine* eng = homer::Engine::Get();
	m_background = eng->Get()->Gfx()->LoadTexture("standby.jpg");
	eng->Get()->Gfx()->DrawTexture(m_background, {255,255,255,255});

	homer::Entity* entity0 = eng->World()->AddEntity("Carrer0");
	homer::Entity* entity2 = eng->World()->AddEntity("AtlasTest");
	entity2->x = 200.0f;
	entity2->y = 200.0f;


	Square* square0 = entity0->AddComponent<Square>();
	entity0->x = eng->WindowWidth() / 2.0f - 25.0f;
	entity0->y = eng->WindowHeight() / 2.0f - 25.0f;
	Controller* newController = entity0->AddComponent<Controller>();
	
	homer::Entity* entity = eng->World()->AddEntity("Animation");
	entity->x = 400.0f;
	entity->y = 400.0f;
	Animation * anima = entity->AddComponent<Animation>();
	anima->Load("misc-2.png");
	anima->InitAnimation(2, 39, 40);
	anima->AddClip("idle", 0, 2, 1.0f);
	anima->Play("idle", true);
	anima->SetScale(5.0f);
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
