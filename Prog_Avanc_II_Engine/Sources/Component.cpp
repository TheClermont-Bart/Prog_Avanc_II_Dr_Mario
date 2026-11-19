#include "Component.h"
#include "Engine.h"

IInput* Component::Input()
{
    return homer::Engine::Get()->Input();
}

IGfx* Component::Gfx()
{
    return homer::Engine::Get()->Gfx();
}

homer::IWorld* Component::World()
{
    return homer::Engine::Get()->World();
}

homer::ICollision* Component::Collision()
{
    return homer::Engine::Get()->Collision();
}