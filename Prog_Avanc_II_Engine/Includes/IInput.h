#pragma once

enum class EKey
{
	EKEY_A,
	EKEY_B,
	EKEY_C,
	EKEY_D,
	EKEY_E,
	EKEY_F,
	EKEY_G,
	EKEY_H,
	EKEY_I,
	EKEY_J,
	EKEY_K,
	EKEY_L,
	EKEY_M,
	EKEY_N,
	EKEY_O,
	EKEY_P,
	EKEY_Q,
	EKEY_R,
	EKEY_S,
	EKEY_T,
	EKEY_U,
	EKEY_V,
	EKEY_W,
	EKEY_X,
	EKEY_Y,
	EKEY_Z,
	EKEY_1,
	EKEY_2,
	EKEY_3,
	EKEY_4,
	EKEY_5,
	EKEY_6,
	EKEY_7,
	EKEY_8,
	EKEY_9,
	EKEY_0,
	EKEY_RETURN,
	EKEY_ESCAPE,
	EKEY_BACKSPACE,
	EKEY_TAB,
	EKEY_SPACE,
	EKEY_MINUS,
	EKEY_EQUALS,
	EKEY_LEFTBRACKET,
	EKEY_RIGHTBRACKET,
	EKEY_BACKSLASH,
	EKEY_MAX
};

class IInput 
{
public:
	virtual ~IInput() = default;

	virtual void Update() = 0;
	virtual bool IsKeyDown(int key) = 0;
	virtual bool IsButtonDown(int button) = 0;
	virtual void GetMousePosition(int* x, int* y) = 0;
};