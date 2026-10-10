#include "Scene1.h"
#include "Engine.h"
#include "Player.h"

void Scene1::Load()
{
	homer::Engine* eng = homer::Engine::Get();

	eng->World()->AddEntity(new Player(100, 100, 200));
}
