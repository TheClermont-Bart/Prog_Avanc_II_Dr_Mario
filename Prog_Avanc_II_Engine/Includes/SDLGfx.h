#pragma once
#include "IGfx.h"

struct SDL_Window;
struct SDL_Renderer;

class SDLGfx final : public IGfx {
public:
	virtual int Init(const char* title, int width, int height) override;
	virtual void Shutdown() override;
	virtual void SetColor(const Color& color) override;
	virtual void Clear() override;
	virtual void Present() override;
	virtual void DrawRect(float x, float y, float w, float h, const Color& color) override;
	virtual ~SDLGfx() = default;
private:
	SDL_Renderer* m_renderer = nullptr;
	SDL_Window* m_window = nullptr;

};