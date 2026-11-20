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

	/// <summary>
	/// Loads a tileset from an image file and generates the tile rectangles based on the specified tile width, height, number of columns, and total count of tiles.
	/// </summary>
	/// <param name="image"></param>
	/// <param name="tileW"></param>
	/// <param name="tileH"></param>
	/// <param name="columns"></param>
	/// <param name="count"></param>
	void LoadTileset(const std::string& image, int tileW, int tileH, int columns, int count);
	/// <summary>
	/// Adds a layer to the tilemap with the specified name and layer data.
	/// </summary>
	/// <param name="name"></param>
	/// <param name="layer"></param>
	void AddLayer(const std::string& name, TLayer layer);
	/// <summary>
	/// Draws a single tile from the tileset at the specified index and position (x, y) with the given tile width and height.
	/// </summary>
	/// <param name="tiledIndex"></param>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="tileW"></param>
	/// <param name="tileH"></param>
	void DrawTile(int tiledIndex, int x, int y, int tileW, int tileH);
	/// <summary>
	///	Draws a layer of tiles from the tilemap using the specified tile width and height. It iterates through the layer data and draws each tile at the appropriate position.
	/// </summary>
	/// <param name="layer"></param>
	/// <param name="tileW"></param>
	/// <param name="tileH"></param>
	void DrawLayer(const TLayer& layer, int tileW, int tileH);
	/// <summary>
	/// Draws all layers of tiles from the tilemap using the specified tile width and height. It iterates through each layer in the tilemap and calls DrawLayer for each one.
	/// </summary>
	/// <param name="tileW"></param>
	/// <param name="tileH"></param>
	void DrawTiles(int tileW, int tileH);
};