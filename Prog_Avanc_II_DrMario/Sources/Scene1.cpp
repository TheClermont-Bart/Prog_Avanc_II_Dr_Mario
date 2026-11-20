#include "Scene1.h"
#include "Engine.h"
#include "PlayerController.h"
#include "Animation.h"
#include "Collider.h"

void Scene1::Load()
{
	m_engine = homer::Engine::Get();

	homer::Entity* player = Instantiate("Player");
	player->x = m_engine->WindowWidth() / 2.0f - 25.0f;
	player->y = m_engine->WindowHeight() / 2.0f - 25.0f;

	Collider* collider = player->AddComponent<Collider>();
	collider->SetSize(39.0f, 40.0f);
	collider->Start();

	Animation* anim = player->AddComponent<Animation>();
	anim->Load("images/testmario.png");
	anim->InitAnimation(2, 39, 40);
	anim->AddClip("idle", 0, 0, 0.2f);
	anim->AddClip("walk", 1, 1, 0.2f);
	anim->Play("idle", true);
	anim->SetScale(2.0f);
	player->AddComponent<PlayerController>();

	homer::Entity* entity2 = Instantiate("AtlasTest");
	entity2->x = m_engine->WindowWidth() - 39.0f * 5.0f;
	entity2->y = m_engine->WindowHeight() - 40.0f * 5.0f;
	Atlas* atlas = entity2->AddComponent<Atlas>();
	atlas->Load("images/testmario.png");
	atlas->AddFrame("frame0", 0, 0, 39, 40);
	atlas->SetFrame("frame0");
	atlas->SetScale(5.0f);

	Collider* collider2 = entity2->AddComponent<Collider>();
	collider2->SetSize(39.0f * 5.0f, 40.0f * 5.0f);
	collider2->Start();
}

void Scene1::Draw()
{
}

void Scene1::Update(float deltaTime)
{
	if (Input()->IsKeyDown(static_cast<int>(EKey::EKEY_BACKSPACE)))
	{
		World()->Load("Scene0");
	}
}


