#pragma once
#include "Iinput.h"

class input final : public IInput {
public:
	virtual void ProcessInput() override;
	virtual bool UpdateInput(float dt) override;
	virtual ~input() = default;
};	