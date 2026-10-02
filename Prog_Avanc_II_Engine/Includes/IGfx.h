#pragma once

#include <unordered_map>
#include <string>

typedef unsigned char uchar;

struct RectI
{
	int x;
	int y;
	int w;
	int h;
};

struct RectF
{
	float x;
	float y;
	float w;
	float h;
};

struct Flip
{
	bool n;
	bool h;
	bool v;
};

class Color
{
public:
	Color(uchar red, uchar green, uchar blue, uchar alpha);

	static const Color& Red;
	static const Color& Green;
	static const Color& Blue;

	uchar r = 255;
	uchar g = 255;
	uchar b = 255;
	uchar a = 255;
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
	virtual void DrawRect(const RectF& rect, const Color& color) = 0;
	virtual void FillRect(float x, float y, float w, float h, const Color& color) = 0;
	virtual void FillRect(const RectF& rect, const Color& color) = 0;
	virtual void DrawLine(float x1, float y1, float x2, float y2, const Color& color) = 0;
	virtual size_t LoadTexture(const std::string& filename) = 0;
	virtual void DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color) = 0;
	virtual void DrawTexture(size_t id, const RectF& dst, const Color& color) = 0;
	virtual void DrawTexture(size_t id, const Color& color) = 0;
	virtual void GetTexture(size_t id, int* w, int* h) = 0;
	/// <summary>
	/// Méthode virtuelle pure qui charge une police depuis un fichier et retourne un identifiant représentant la police chargée.
	/// </summary>
	/// <param name="filename">Nom ou chemin du fichier de la police à charger.</param>
	/// <param name="fontSize">Taille de la police à charger (par exemple en points).</param>
	/// <returns>Un identifiant (size_t) correspondant à la police chargée, à utiliser pour référencer cette police.</returns>
	virtual size_t LoadFont(const std::string& filename, int fontSize) = 0;
	virtual void DrawString(const std::string& text, size_t fontId, float x, float y, const Color& color) = 0;
	/// <summary>
	/// Méthode virtuelle pure qui calcule la taille en pixels du texte rendu avec la police spécifiée et retourne les dimensions via des paramètres de sortie.
	/// </summary>
	/// <param name="text">Chaîne de texte à mesurer.</param>
	/// <param name="fontId">Identifiant de la police à utiliser pour le rendu.</param>
	/// <param name="w">Pointeur vers un int qui recevra la largeur en pixels (doit être non nul).</param>
	/// <param name="h">Pointeur vers un int qui recevra la hauteur en pixels (doit être non nul).</param>
	virtual void GetTextSize(const std::string& text, size_t fontId, int* w, int* h) = 0;
};