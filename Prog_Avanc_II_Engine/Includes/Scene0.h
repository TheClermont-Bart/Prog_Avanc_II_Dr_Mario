#pragma once
#include "IScene.h"

class Scene0 : public homer::IScene
{
public:
	Scene0() = default;
	~Scene0() override = default;
	void Load() override;
	void Draw();
	void Update(float deltaTime);
	void Unload();
private:
	size_t m_background = 0;
};