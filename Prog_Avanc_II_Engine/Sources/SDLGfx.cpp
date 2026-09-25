#include "SDL.h"
#include "SDLGfx.h"
#include "Engine.h"

const Color& Color::Red = Color(255, 0, 0, 255);
const Color& Color::Green = Color(0, 255, 0, 255);
const Color& Color::Blue = Color(0, 0, 255, 255);

int SDLGfx::Init(const char* title, int width, int height)
{
	ILogger* log = homer::Engine::Get()->Logger();

	if (SDL_Init( SDL_INIT_EVENTS) != 0) {
		log->Log(SDL_GetError());
		return false;
	}

	int x = SDL_WINDOWPOS_CENTERED;
	int y = SDL_WINDOWPOS_CENTERED;
	uint32_t flags = SDL_WINDOW_TOOLTIP;

	m_window = SDL_CreateWindow(title, x, y, width, height, flags);
	if (!m_window) {
		log->Log(SDL_GetError());
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if (!m_renderer) {
		log->Log(SDL_GetError());
		return false;
	}

	return true;
}


Color::Color(uchar red, uchar green, uchar blue, uchar alpha){}

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

void SDLGfx::DrawRect(const RectF& rect, const Color& color) 
{

};

void SDLGfx::FillRect(float x, float y, float w, float h, const Color& color)
{

};

void SDLGfx::FillRect(const RectF& rect, const Color& color)
{

};

void SDLGfx::DrawLine(float x1, float y1, float x2, float y2, const Color& color)
{

};

size_t SDLGfx::LoadTexture(const std::string& filename)
{
	return NULL;
};

void SDLGfx::DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color)
{

};

void SDLGfx::DrawTexture(size_t id, const RectF& dst, const Color& color)
{

};

void SDLGfx::DrawTexture(size_t id, const Color& color)
{

};

void SDLGfx::GetTexture(size_t id, int* w, int* h)
{

};

size_t SDLGfx::LoadFont(const std::string& filename, int fontSize)
{
	return NULL;
};

void SDLGfx::DrawString(const std::string& text, size_t fontId, float x, float y, const Color& color)
{

};

void SDLGfx::GetTextSize(const std::string& text, size_t fontId, int* w, int* h)
{

};

void SDLGfx::Shutdown()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}