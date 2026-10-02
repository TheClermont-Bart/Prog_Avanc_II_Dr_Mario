#pragma once 

class Entity
{
public :
    virtual ~Entity() = default;
	virtual void Start() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Draw() = 0;
	virtual void Destroy() = 0;
};