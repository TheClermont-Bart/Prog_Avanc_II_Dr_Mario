#pragma once
#include "Component.h"
#include "IUpdateable.h"

class Controller : public Component, public IUpdateable
{
public:
	Controller();
	void Update(float deltaTime) override;
private:
	
};