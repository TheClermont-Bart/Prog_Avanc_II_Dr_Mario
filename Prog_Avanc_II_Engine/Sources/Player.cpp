#include "Player.h"
#include "Engine.h"
#include "Bullet.h"

void Player::Update(float deltaTime)
{
	IInput* input = homer::Engine::Get()->Input();

	if (input->IsKeyDown(static_cast<int>(EKey::EKEY_W)))
	{
		m_rectY -= m_rectSpeed * deltaTime;
	}

	if (input->IsKeyDown(static_cast<int>(EKey::EKEY_S)))
	{
		m_rectY += m_rectSpeed * deltaTime;
	}

	if (input->IsKeyDown(static_cast<int>(EKey::EKEY_A)))
	{
		m_rectX -= m_rectSpeed * deltaTime;
	}

	if (input->IsKeyDown(static_cast<int>(EKey::EKEY_D)))
	{
		m_rectX += m_rectSpeed * deltaTime;
	}

	if(input->IsKeyDown(static_cast<int>(EKey::EKEY_SPACE)))
	{
		if(m_shoot == false)
		{
			m_shoot = true;
			homer::Engine::Get()->World()->AddEntity(new Bullet(m_rectX + 25, m_rectY + 25, 300));
		}
	} 
	else
	{
		m_shoot = false;
	}

}

void Player::Draw()
{
	homer::Engine::Get()->Gfx()->FillRect(m_rectX, m_rectY, 50, 50, Color(255, 0, 0, 255));
}

