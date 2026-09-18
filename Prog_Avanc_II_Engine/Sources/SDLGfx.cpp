#include "SDL.h"
#include "SDLGfx.h"

int SDLGfx::Init(const char* title, int width, int height)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Log(SDL_GetError());
		return false;
	}

	int x = SDL_WINDOWPOS_CENTERED;
	int y = SDL_WINDOWPOS_CENTERED;
	uint32_t flags = SDL_WINDOW_TOOLTIP;

	m_window = SDL_CreateWindow(title, x, y, width, height, flags);
	if (!m_window) {
		SDL_Log(SDL_GetError());
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if (!m_renderer) {
		SDL_Log(SDL_GetError());
		return false;
	}

	return true;
}

void SDLGfx::Shutdown()
{
	SDL_DestroyRenderer(m_renderer);

	SDL_DestroyWindow(m_window);

	SDL_Quit();
}

void SDLGfx::SetColor(const Color& color)
{
	SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a); 
}

void SDLGfx::Clear()
{
	SDL_RenderClear(m_renderer);
}

void SDLGfx::Present()
{
	SDL_RenderPresent(m_renderer);
}

void SDLGfx::DrawRect(float x, float y, float w, float h, const Color& color)
{
	SDL_Rect rect = { 0 };
	rect.x = static_cast<int>(x);
	rect.y = static_cast<int>(y);
	rect.w = static_cast<int>(w);
	rect.h = static_cast<int>(h);
	SDL_SetRenderDrawColor(m_renderer,color.r, color.g, color.b, color.a);
	SDL_RenderDrawRect(m_renderer, &rect);
}
