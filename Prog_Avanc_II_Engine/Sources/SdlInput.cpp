#include "SDL.h"
#include "SdlInput.h"
#include "Engine.h"

char keys[static_cast<int>(EKey::EKEY_MAX)] =
{
	SDL_SCANCODE_A,
	SDL_SCANCODE_B,
	SDL_SCANCODE_C,
	SDL_SCANCODE_D,
	SDL_SCANCODE_E,
	SDL_SCANCODE_F,
	SDL_SCANCODE_G,
	SDL_SCANCODE_H,
	SDL_SCANCODE_I,
	SDL_SCANCODE_J,
	SDL_SCANCODE_K,
	SDL_SCANCODE_L,
	SDL_SCANCODE_M,
	SDL_SCANCODE_N,
	SDL_SCANCODE_O,
	SDL_SCANCODE_P,
	SDL_SCANCODE_Q,
	SDL_SCANCODE_R,
	SDL_SCANCODE_S,
	SDL_SCANCODE_T,
	SDL_SCANCODE_U,
	SDL_SCANCODE_V,
	SDL_SCANCODE_W,
	SDL_SCANCODE_X,
	SDL_SCANCODE_Y,
	SDL_SCANCODE_Z,
	SDL_SCANCODE_1,
	SDL_SCANCODE_2,
	SDL_SCANCODE_3,
	SDL_SCANCODE_4,
	SDL_SCANCODE_5,
	SDL_SCANCODE_6,
	SDL_SCANCODE_7,
	SDL_SCANCODE_8,
	SDL_SCANCODE_9,
	SDL_SCANCODE_0,
	SDL_SCANCODE_RETURN,
	SDL_SCANCODE_ESCAPE,
	SDL_SCANCODE_BACKSPACE,
	SDL_SCANCODE_TAB,
	SDL_SCANCODE_SPACE,
	SDL_SCANCODE_MINUS,
	SDL_SCANCODE_EQUALS,
	SDL_SCANCODE_LEFTBRACKET,
	SDL_SCANCODE_RIGHTBRACKET,
	SDL_SCANCODE_BACKSLASH
};

void SdlInput::Update()
{
	SDL_Event _event;

	while (SDL_PollEvent(&_event))
	{
		switch (_event.type)
		{
		case SDL_QUIT:
		{
			homer::Engine::Get()->Exit();
			break;
		}
		case SDL_MOUSEBUTTONDOWN:
		{
			SDL_MouseButtonEvent _buttonDown = _event.button;
			//SDL_Log("Button down : %d)", _buttonDown.button);
			//SDL_Log("at (%d, %d)", _buttonDown.x, _buttonDown.y);
			break;
		}
		case SDL_MOUSEBUTTONUP:
		{
			SDL_MouseButtonEvent _buttonUp = _event.button;
			//SDL_Log("Button up : %d", _buttonUp.button);
			//SDL_Log("at (%d, %d)", _buttonUp.x, _buttonUp.y);
			break;
		}
		case SDL_MOUSEMOTION:
		{
			SDL_MouseMotionEvent _motion = _event.motion;

			//SDL_Log("%d, %d", _motion.x, _motion.y);
			break;
		}
		default:
			break;
		}
	}

	const unsigned char* buffer;
	buffer = SDL_GetKeyboardState(NULL);
	if (buffer != NULL)
	{
		m_keyStates = buffer;
	}
}

bool SdlInput::IsKeyDown(int key)
{
	if (m_keyStates == nullptr)
	{
		return false;
	}

	if (key < 0 || key >= static_cast<int>(EKey::EKEY_MAX))
	{
		return false;
	}

	return m_keyStates[static_cast<unsigned char>(keys[key])];
}

bool SdlInput::IsButtonDown(int button)
{
	if (button < 0 || button >= 3)
	{
		return false;
	}

	return m_mouseButtonStates[button];
}

void SdlInput::GetMousePosition(int* x, int* y)
{
	// Dans update pourtant....
}
