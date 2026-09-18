#pragma once
//REVOIR NOTE DE COURS PAGE 11
class IInput {
public:
	virtual void ProcessInput() = 0;
	virtual bool UpdateInput(float dt) = 0;
	virtual ~IInput() = default;
};