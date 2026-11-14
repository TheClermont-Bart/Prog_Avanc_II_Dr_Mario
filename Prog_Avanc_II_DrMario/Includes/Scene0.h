#pragma once
#include "BaseScene.h"
#include <map>
#include <vector>
#include <string>
#include "IGfx.h"

typedef std::vector<RectI> TTileset;
typedef std::vector<std::vector<unsigned int>> TLayer;
typedef std::map<std::string, TLayer> TTilemap;


namespace homer { class Engine; }

class Scene0 : public homer::BaseScene	
{
public:
	Scene0() = default;
	~Scene0() override = default;
	void Load() override;
	void Draw();
	void Update(float deltaTime);
	void Unload();
private:
	size_t m_tilesetTexture = 0;
	TTileset m_tileset;
	TTilemap m_tilemap;

	void LoadTileset(const std::string& image, int tileW, int tileH, int columns, int count);
	void AddLayer(const std::string& name, TLayer layer);
	void DrawTile(int tiledIndex, int x, int y, int tileW, int tileH);
	void DrawLayer(const TLayer& layer, int tileW, int tileH);
	void DrawTiles(int tileW, int tileH);
};