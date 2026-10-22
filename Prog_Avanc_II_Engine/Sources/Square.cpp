#include "Square.h"
#include "Engine.h"

Square::Square()
{
}

Square::~Square()
{
}

void Square::Draw() 
{
	int h = homer::Engine::Get()->WindowHeight();
	int w = homer::Engine::Get()->WindowWidth();

	homer::Engine::Get()->Gfx()->FillRect((w-50)/2, (h-50)/2, 50, 50, Color(255, 0, 0, 255));
}
