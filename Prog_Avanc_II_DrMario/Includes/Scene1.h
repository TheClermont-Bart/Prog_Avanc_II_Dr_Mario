#pragma once
#include "BaseScene.h"

namespace homer { class Engine; }

class Scene1 : public homer::BaseScene
{
public:
	Scene1() = default;
	~Scene1() override = default;
	void Load() override;
	void Draw() override;
	void Update(float deltaTime) override;
	void Unload() override {};
private:
	homer::Engine* m_engine = nullptr;
};