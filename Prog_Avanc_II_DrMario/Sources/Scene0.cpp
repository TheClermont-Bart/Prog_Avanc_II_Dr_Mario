#include "Scene0.h"
#include "Engine.h"
#include "Square.h"
#include "Sprite.h"
#include "Controller.h"
#include "Atlas.h"
#include "Animation.h"

void Scene0::Load()
{
	LoadTileset("images/tilepourtileset.png", 32, 32, 16, 176);

	TLayer layer1 = {
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,22,25,25,25,25,25,25,25},
	{145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,1,1,1,1,1,1,1,1},
	{145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,2,2,2,2,2,2,2,2}
	};
	AddLayer("layer1", layer1);

	TLayer layer2 = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,16,16,16,16},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,117,119,115,0,0,0,0,0,0,0,0,117,119,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,120,116,0,0,0,0,0,0,0,0,0,120,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,117,119,0,0,0,0,0,0,0,0,0,0,0,113,0,0},
		{0,0,0,0,0,0,0,0,0,0,120,0,0,0,0,0,0,145,150,145,145,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,113,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,88,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,113,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,113,0,0,5,0,0,88,88,150,145,145,145,145,0,0,0,0,0,0,0,97,0,0},
		{0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,97,0,0},
		{0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,98,0,0,0,97,0,0},
		{0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,128,0,0,0,97,0,0},
		{0,0,0,0,0,8,0,0,0,0,0,0,0,0,96,0,0,129,129,129,0,0,97,0,0},
		{87,85,0,0,0,8,0,0,0,0,0,86,87,85,96,0,0,134,132,134,0,0,97,142,142},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};
	AddLayer("layer2", layer2);

	homer::Entity* entity = Instantiate("Animation");
	entity->x = 50.0f;
	entity->y = 320.0f;
	Animation * anima = entity->AddComponent<Animation>();
	anima->Load("images/testmario.png");
	anima->InitAnimation(2, 39, 40);
	anima->AddClip("idle", 0, 2, 1.0f);
	anima->Play("idle", true);
	anima->SetScale(5.0f);
}

void Scene0::Update(float deltatime)
{
	if (Input()->IsKeyDown(static_cast<int>(EKey::EKEY_RETURN)))
	{
		World()->Load("Scene1");
	}

	if (Input()->IsKeyDown(static_cast<int>(EKey::EKEY_R)))
	{
		homer::Entity* entity = World()->FindEntity("Animation");
		if (entity != nullptr)
		{
			entity->RemoveComponent<Animation>();
		}
	}
}

void Scene0::Draw()
{
	DrawTiles(32, 32);
}

void Scene0::Unload()
{

}

void Scene0::LoadTileset(const std::string& image, int tileW, int tileH, int columns, int count)
{
	m_tilesetTexture = Gfx()->LoadTexture(image);

	for (int i = 0; i < count; i++)
	{
		int row = i / columns;
		int col = i - row * columns;
		m_tileset.push_back(RectI{ col * tileW, row * tileH, tileW, tileH });
	}
}

void Scene0::AddLayer(const std::string& name, TLayer layer)
{
	if (m_tilemap.count(name) == 0)
	{
		m_tilemap.emplace(name, layer);
	}
}

void Scene0::DrawTile(int tiledIndex, int x, int y, int tileW, int tileH)
{
	int index = tiledIndex - 1;

	if (index < 0)
	{
		return;
	}

	const RectI& src = m_tileset[index];
	RectF dst{
		static_cast<float>(x * tileW),
		static_cast<float>(y * tileH),
		static_cast<float>(tileW),
		static_cast<float>(tileH)
	};

	Flip flip{};
	Gfx()->DrawTexture(m_tilesetTexture, src, dst, 0.0, flip, Color(255, 255, 255, 255));
}

void Scene0::DrawLayer(const TLayer& layer, int tileW, int tileH)
{
	for (int y = 0; y < static_cast<int>(layer.size()); y++)
	{
		for (int x = 0; x < static_cast<int>(layer[y].size()); x++)
		{
			DrawTile(layer[y][x], x, y, tileW, tileH);
		}
	}
}

void Scene0::DrawTiles(int tileW, int tileH)
{
	for (const auto& layer : m_tilemap)
	{
		DrawLayer(layer.second, tileW, tileH);
	}
}
