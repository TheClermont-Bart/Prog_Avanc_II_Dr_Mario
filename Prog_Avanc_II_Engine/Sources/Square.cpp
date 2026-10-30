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
	homer::Engine::Get()->Gfx()->FillRect(m_Entity->x, m_Entity->y, 50, 50, Color(255, 0, 0, 255));
}
