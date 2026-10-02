#pragma once
#include "IGfx.h"
#include "ILogger.h"

struct SDL_Window;
struct SDL_Renderer;
struct _TTF_Font;
struct SDL_Texture;	

class SdlGfx final : public IGfx {
public:
	virtual int Init(const char* title, int width, int height) override;
	virtual void Shutdown() override;
	virtual void SetColor(const Color& color) override;
	virtual void Clear() override;
	virtual void Present() override;
	virtual void DrawRect(float x, float y, float w, float h, const Color& color) override;
	virtual void DrawRect(const RectF& rect, const Color& color) override;
	virtual void FillRect(float x, float y, float w, float h, const Color& color) override;
	virtual void FillRect(const RectF& rect, const Color& color) override;
	virtual void DrawLine(float x1, float y1, float x2, float y2, const Color& color) override;
	/// <summary>
	/// Charge une texture depuis un fichier et renvoie son identifiant.
	/// </summary>
	/// <param name="filename">Le chemin ou le nom du fichier de la texture à charger.</param>
	/// <returns>Un identifiant (size_t) représentant la texture chargée.</returns>
	virtual size_t LoadTexture(const std::string& filename) override;
	virtual void DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color) override;
	virtual void DrawTexture(size_t id, const RectF& dst, const Color& color) override;
	virtual void DrawTexture(size_t id, const Color& color) override;
	virtual void GetTexture(size_t id, int* w, int* h) override;
	/// <summary>
	/// Charge une police depuis un fichier et retourne un identifiant pour la police chargée.
	/// </summary>
	/// <param name="filename">Chemin vers le fichier de police à charger.</param>
	/// <param name="fontSize">Taille de la police à utiliser (par exemple en points).</param>
	/// <returns>Un identifiant (size_t) représentant la police chargée.</returns>
	virtual size_t LoadFont(const std::string& filename, int fontSize) override;
	virtual void DrawString(const std::string& text, size_t fontId, float x, float y, const Color& color) override;
	/// <summary>
	/// Méthode virtuelle (override) qui calcule la taille du texte rendu avec la police spécifiée et écrit la largeur et la hauteur dans les paramètres fournis.
	/// </summary>
	/// <param name="text">La chaîne de caractères à mesurer.</param>
	/// <param name="fontId">L'identifiant de la police à utiliser pour le rendu.</param>
	/// <param name="w">Pointeur vers un int où sera écrit la largeur calculée (en pixels).</param>
	/// <param name="h">Pointeur vers un int où sera écrite la hauteur calculée (en pixels).</param>
	virtual void GetTextSize(const std::string& text, size_t fontId, int* w, int* h) override;
	virtual ~SdlGfx() = default;
private:
	SDL_Renderer* m_renderer = nullptr;
	SDL_Window* m_window = nullptr;
	ILogger* log = nullptr;
	std::unordered_map<size_t, SDL_Texture*> m_textureCache;
	std::unordered_map<size_t, _TTF_Font*> m_fontCache;

};