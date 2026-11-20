#pragma once
#include <string>

class IInput;
class IGfx;

namespace homer
{
    class Entity;
    class IWorld;

    class BaseScene
    {
    public:
        virtual ~BaseScene() = default;
        virtual void Load() = 0;
        virtual void Draw() = 0;
        virtual void Update(float deltaTime) {}
        virtual void Unload() = 0;
    protected:
        Entity* Instantiate(const std::string& name);
        IInput* Input();
        IGfx* Gfx();
        IWorld* World();
    };
}
