#pragma once
#include "IWorld.h"
#include "Entity.h"
#include <vector>

class World final : public IWorld
{
public:
	World();
    virtual ~World() = default;
    virtual void FindEntity(const char* name) override;
private:
    std::vector<Entity*> m_entityInWorld;
};