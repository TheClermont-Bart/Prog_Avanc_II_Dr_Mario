#pragma once
#include <SDL_image.h>


class Color {
public:
	int r, g, b, a;
};

class IGfx {
public:
	virtual ~IGfx() = default;
	virtual int Init(const char* title, int width, int height) = 0;
	virtual void Shutdown() = 0;
	virtual void SetColor(const Color& color) = 0;
	virtual void Clear() = 0;
	virtual void Present() = 0;
	virtual void DrawRect(float x, float y, float w, float h, const Color& color) = 0;

};