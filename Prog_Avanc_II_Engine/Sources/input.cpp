#include "SDL.h"
#include "input.h"

void input::ProcessInput() {
	SDL_Event _event;
	while (SDL_PollEvent(&_event)) {
		switch (_event.type) {
			case SDL_QUIT:
				SDL_Quit();
				break;
			case SDL_MOUSEBUTTONDOWN:
				SDL_MouseButtonEvent _buttonDown = _event.button;
				SDL_Log("Button down : %d)", _buttonDown.button);
				SDL_Log("at (%d, %d)", _buttonDown.x, _buttonDown.y);
				break;
			case SDL_MOUSEBUTTONUP:
				SDL_MouseButtonEvent _buttonUp = _event.button;
				SDL_Log("Button up : %d", _buttonUp.button);
				SDL_Log("at (%d, %d)", _buttonUp.x, _buttonUp.y);
				break;
			case SDL_KEYDOWN:
				SDL_KeyboardEvent _keyDown = _event.key;
				SDL_Log("Key down : %s", SDL_GetKeyName(_keyDown.keysym.sym));
				break;
			case SDL_KEYUP:
				SDL_KeyboardEvent _keyUp = _event.key;
				SDL_Log("Key up : %s", SDL_GetKeyName(_keyUp.keysym.sym));
				break;
		}
	}
}

bool input::UpdateInput(float dt) {
	const unsigned char* _keyStates = SDL_GetKeyboardState(nullptr);

	if (_keyStates[SDL_SCANCODE_W]) {
		return true;
	}
	if (_keyStates[SDL_SCANCODE_S]) {
		return true;
	}
	if (_keyStates[SDL_SCANCODE_A]) {
		return true;
	}
	if (_keyStates[SDL_SCANCODE_D]) {
		return true;
	}

	return false;
}