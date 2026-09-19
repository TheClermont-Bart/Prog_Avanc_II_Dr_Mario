#pragma once
#include "IInput.h"

class SdlInput final : public IInput 
{
public:
	virtual ~SdlInput() = default;

	virtual void Update() override;
	virtual bool IsKeyDown(int key) override;
	virtual bool IsButtonDown(int button) override;
	virtual void GetMousePosition(int* x, int* y) override;

private:
	const unsigned char* m_keyStates = nullptr;
	int m_mouseX = 0;
	int m_mouseY = 0;
	bool m_mouseButtonStates[3] = { false, false, false };
};	