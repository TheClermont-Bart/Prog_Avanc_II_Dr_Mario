#pragma once
#include "IScene.h"

class Scene1 : public homer::IScene
{
public:
	Scene1() = default;
	~Scene1() override = default;
	void Load() override;
	void Draw() override{};
	void Update(float deltaTime) {}
	void Unload() override {};
};