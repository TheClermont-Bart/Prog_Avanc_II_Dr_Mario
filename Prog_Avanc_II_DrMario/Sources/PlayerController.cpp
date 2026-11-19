#include "PlayerController.h"
#include "Entity.h"
#include "Engine.h"
#include "Animation.h"
#include "Bullet.h"
#include "Collider.h"

PlayerController::PlayerController()	
{

}

void PlayerController::Update(float deltaTime)
{
	float speed = 200.0f;
	bool moving = false;
	int face = 0;

    if (Input()->IsKeyDown(static_cast<int>(EKey::EKEY_A)))
    {
        m_Entity->x -= speed * deltaTime;
        moving = true;
        face = -1;
    }
    if (Input()->IsKeyDown(static_cast<int>(EKey::EKEY_D)))
    {
        m_Entity->x += speed * deltaTime;
        moving = true;
        face = 1;
    }
    if (Input()->IsKeyDown(static_cast<int>(EKey::EKEY_W)))
    {
        m_Entity->y -= speed * deltaTime;
        moving = true;
    }
    if (Input()->IsKeyDown(static_cast<int>(EKey::EKEY_S)))
    {
        m_Entity->y += speed * deltaTime;
        moving = true;
    }

    Animation* anim = m_Entity->GetComponent<Animation>();

    if (anim != nullptr)
    {
        const std::string clip = moving ? "walk" : "idle";

        if (m_currentClip != clip)
        {
            anim->Play(clip, true);
            m_currentClip = clip;
        }

        if (face != 0)
        {
            anim->SetFlipH(face < 0);
        }
    }

    bool spaceDown = Input()->IsKeyDown(static_cast<int>(EKey::EKEY_SPACE));

    if (spaceDown && !m_spaceWasDown)
    {
        static int count = 0;
        homer::Entity* spawned = World()->AddEntity("Spawn");
        spawned->x = m_Entity->x + 40.0f;
        spawned->y = m_Entity->y + 20.0f;

        Collider* collider = spawned->AddComponent<Collider>();
        collider->SetSize(10.0f, 10.0f);
		collider->Start();
        
        spawned->AddComponent<Bullet>()->SetSpeed(300.0f);
        m_lastSpawn = spawned;
    }

    m_spaceWasDown = spaceDown;
    bool destroyDown = Input()->IsKeyDown(static_cast<int>(EKey::EKEY_X));

    if (destroyDown && !m_destroyWasDown && m_lastSpawn != nullptr)
    {
        World()->RemoveEntity(m_lastSpawn);
        m_lastSpawn = nullptr;
    }
    m_destroyWasDown = destroyDown;
    
}
