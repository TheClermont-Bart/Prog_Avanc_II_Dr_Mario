#include "SDL.h"
#include "SDLGfx.h"
#include "Engine.h"


const Color& Color::Red = Color(255, 0, 0, 255);
const Color& Color::Green = Color(0, 255, 0, 255);
const Color& Color::Blue = Color(0, 0, 255, 255);

int SdlGfx::Init(const char* title, int width, int height)
{
	log = homer::Engine::Get()->Logger();

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		log->Log(SDL_GetError());
		return false;
	}

	int x = SDL_WINDOWPOS_CENTERED;
	int y = SDL_WINDOWPOS_CENTERED;
	uint32_t flags = 0;

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

	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
	TTF_Init();

	return true;
}


Color::Color(uchar red, uchar green, uchar blue, uchar alpha) : r(red), g(green), b(blue), a(alpha) {}

void SdlGfx::SetColor(const Color& color)
{
	SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a); 
}

void SdlGfx::Clear()
{
	SDL_RenderClear(m_renderer);
}

void SdlGfx::Present()
{
	SDL_RenderPresent(m_renderer);
}

void SdlGfx::DrawRect(float x, float y, float w, float h, const Color& color)
{
	SDL_Rect rect = { 0 };
	rect.x = static_cast<int>(x);
	rect.y = static_cast<int>(y);
	rect.w = static_cast<int>(w);
	rect.h = static_cast<int>(h);
	SDL_SetRenderDrawColor(m_renderer,color.r, color.g, color.b, color.a);
	SDL_RenderDrawRect(m_renderer, &rect);
}

void SdlGfx::DrawRect(const RectF& rect, const Color& color) 
{
	DrawRect(rect.x, rect.y, rect.w, rect.h, color);
};

void SdlGfx::FillRect(float x, float y, float w, float h, const Color& color)
{
	SDL_Rect rect = { 0 };
	rect.x = static_cast<int>(x);
	rect.y = static_cast<int>(y);
	rect.w = static_cast<int>(w);
	rect.h = static_cast<int>(h);
	SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(m_renderer, &rect);
};

void SdlGfx::FillRect(const RectF& rect, const Color& color)
{
	FillRect(rect.x, rect.y, rect.w, rect.h, color);
};

void SdlGfx::DrawLine(float x1, float y1, float x2, float y2, const Color& color)
{
	SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawLine(m_renderer, static_cast<int>(x1), static_cast<int>(y1), static_cast<int>(x2), static_cast<int>(y2));
};

size_t SdlGfx::LoadTexture(const std::string& filename)
{
	const size_t _textureId = std::hash<std::string>()(filename);

	if (m_textureCache.find(_textureId) != m_textureCache.end())
	{
		return _textureId;
	}

	char* base = SDL_GetBasePath();
	const char* path = filename.c_str();

	std::string full = std::string(base) + filename;
	SDL_free(base);

	log->Log(std::string("LE PATH DE L'IMAGE EST : ") + full);

	SDL_Surface* loadSurface = IMG_Load(full.c_str());

	if (loadSurface == nullptr)
	{
		log->Log("IMG FAIL TO LOAD \n");
		return static_cast<size_t>(-1);
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, loadSurface);
	SDL_FreeSurface(loadSurface);

	if (texture != nullptr)
	{
		m_textureCache[_textureId] = texture;
		return _textureId;
	}

	return static_cast<size_t>(-1);
};

void SdlGfx::DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color)
{
	SDL_RendererFlip sdl_Flip = static_cast<SDL_RendererFlip>((flip.h * SDL_FLIP_HORIZONTAL) | (flip.v * SDL_FLIP_VERTICAL));

	SDL_Rect dst_rect = { 0 };
	dst_rect.x = static_cast<int>(dst.x);
	dst_rect.y = static_cast<int>(dst.y);
	dst_rect.w = static_cast<int>(dst.w);
	dst_rect.h = static_cast<int>(dst.h);

	SDL_Rect src_rect = { 0 };
	src_rect.x = src.x;
	src_rect.y = src.y;
	src_rect.w = src.w;
	src_rect.h = src.h;

	SDL_SetTextureAlphaMod(m_textureCache[id], color.a);
	SDL_SetTextureColorMod(m_textureCache[id], color.r, color.g, color.b);
	SDL_RenderCopyEx(m_renderer, m_textureCache[id], &src_rect, &dst_rect, angle, nullptr, sdl_Flip);
};

void SdlGfx::DrawTexture(size_t id, const RectF& dst, const Color& color)
{
	int w = 0;
	int h = 0;
	GetTexture(id, &w, &h);

	RectI src;
	src.h = h;
	src.w = w;
	src.x = 0;
	src.y = 0;

	Flip flip;
	flip.h = 0;
	flip.n = 0;
	flip.v = 0;

	DrawTexture(id, src, dst, 0.0, flip, color);
};

void SdlGfx::DrawTexture(size_t id, const Color& color)
{
	int w = 0;
	int h = 0;
	GetTexture(id, &w, &h);

	RectF dst;
	dst.h = static_cast<float>(h);
	dst.w = static_cast<float>(w);
	dst.x = 0.0f;
	dst.y = 0.0f;

	DrawTexture(id, dst, color);
};

void SdlGfx::GetTexture(size_t id, int* w, int* h)
{
	SDL_QueryTexture(m_textureCache[id], nullptr, nullptr, w, h);
};

size_t SdlGfx::LoadFont(const std::string& filename, int fontSize)
{
	const size_t _fontId = std::hash<std::string>()(filename);

	TTF_OpenFont(filename.c_str(), fontSize);

	if (m_fontCache.find(_fontId) != m_fontCache.end())
	{
		return _fontId;
	}

	TTF_Font* font = TTF_OpenFont(filename.c_str(), fontSize);
	if (font != nullptr)
	{
		m_fontCache[_fontId] = font;
		return _fontId;
	}

	return static_cast<size_t>(-1);
};

void SdlGfx::DrawString(const std::string& text, size_t fontId, float x, float y, const Color& color)
{
	if (m_fontCache.count(fontId) > 0)
	{
		TTF_Font* _font = m_fontCache[fontId];
		SDL_Color _color = { color.r, color.g, color.b, color.a };
		SDL_Surface* _surface = TTF_RenderText_Solid(_font, text.c_str(), _color);

		if (_surface == nullptr)
		{
			return;
		}

		SDL_Texture* _texture = SDL_CreateTextureFromSurface(m_renderer, _surface);
		SDL_Rect _dst;
		_dst.x = static_cast<int>(x);
		_dst.y = static_cast<int>(y);
		_dst.w = _surface->w;
		_dst.h = _surface->h;

		SDL_RenderCopy(m_renderer, _texture, nullptr, &_dst);
		SDL_DestroyTexture(_texture);
		SDL_FreeSurface(_surface);
	}
};

void SdlGfx::GetTextSize(const std::string& text, size_t fontId, int* w, int* h)
{
	TTF_SizeText(m_fontCache[fontId], text.c_str(), w, h);
};

void SdlGfx::Shutdown()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	TTF_Quit();
	SDL_Quit();
}