#pragma once
#include "Component.h"
#include "IUpdateable.h"
#include <string>

namespace homer { class Entity; }

class PlayerController : public Component, public IUpdateable
{
public:
	PlayerController();
	void Update(float deltaTime) override;
private:
	std::string m_currentClip;
	bool m_spaceWasDown = false;
	bool m_destroyWasDown = false;
	homer::Entity* m_lastSpawn = nullptr;
};