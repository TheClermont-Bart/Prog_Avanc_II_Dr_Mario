#include "BaseScene.h"
#include "Engine.h"
#include "Entity.h"

homer::Entity* homer::BaseScene::Instantiate(const std::string& name)
{
    return Engine::Get()->World()->AddEntity(name);
}

homer::IWorld* homer::BaseScene::World()
{
    return homer::Engine::Get()->World();
}

IInput* homer::BaseScene::Input()
{
    return Engine::Get()->Input();
}

IGfx* homer::BaseScene::Gfx()
{
    return Engine::Get()->Gfx();
}

