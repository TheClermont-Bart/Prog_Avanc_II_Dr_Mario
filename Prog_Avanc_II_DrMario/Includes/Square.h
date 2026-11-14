#pragma once
#include "Component.h"
#include "IDrawable.h"

class Square : public Component, public IDrawable
{
public:
	Square();
	~Square();
	
	virtual void Draw();

private:
};