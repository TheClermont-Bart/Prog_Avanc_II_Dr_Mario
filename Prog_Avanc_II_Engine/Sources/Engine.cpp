#include "Engine.h"
#include "SDLGfx.h"
#include "SdlInput.h"
#include "Console_Log.h"	
#include <Windows.h>
#include <ctime>

bool homer::Engine::Init(const char* title, int width, int height)
{
	m_gfx = new SDLGfx();
	m_input = new SdlInput();
	m_logger = new Console_Log();

	if (!m_gfx->Init(title, width, height))
	{
		Shutdown();
		return false;
	}

	m_isInit = true;
	return m_isInit;
}

void homer::Engine::Start()
{
	if (!m_isInit)
	{
		if (!Init("Unknown Title", 800, 600))
		{
			return;
		}
	}

	m_isRunning = true;
	clock_t _end = clock();

	while (m_isRunning)
	{
		clock_t _start = clock();
		m_deltaTime = static_cast<float>(_start - _end) / CLOCKS_PER_SEC;
		_end = _start;

		ProcessInput();
		Update(m_deltaTime);
		Render();
		clock_t frametime = _start + CLOCKS_PER_SEC / 60 - clock();

		if (frametime > 0)
		{
			Sleep(frametime);
		}
	}

	Shutdown();
}

void homer::Engine::ProcessInput()
{
	m_input->Update();

	for (int i = static_cast<int>(EKey::EKEY_A); i <= static_cast<int>(EKey::EKEY_MAX); ++i)
	{
		if (m_input->IsKeyDown(i))
		{
			std::string key(1, static_cast<char>('A' + i));
			m_logger->Log("Touche : " + key);
		}
	}

	for (int i = 1; i < 3; ++i)
	{
		if (m_input->IsButtonDown(i))
		{
			m_logger->Log("Mouse button " + std::to_string(i));
		}
	}
}

void homer::Engine::Update(float dt)
{
	if (m_input->IsKeyDown(static_cast<int>(EKey::EKEY_W)))
	{
		m_rectY -= m_rectSpeed * dt;
	}

	if (m_input->IsKeyDown(static_cast<int>(EKey::EKEY_S)))
	{
		m_rectY += m_rectSpeed * dt;
	}

	if (m_input->IsKeyDown(static_cast<int>(EKey::EKEY_A)))
	{
		m_rectX -= m_rectSpeed * dt;
	}

	if (m_input->IsKeyDown(static_cast<int>(EKey::EKEY_D)))
	{
		m_rectX += m_rectSpeed * dt;
	}
}

void homer::Engine::Render()
{
	m_gfx->SetColor({ 0, 0, 0, 255 });
	m_gfx->Clear();

	m_gfx->DrawRect(m_rectX, m_rectY, 100.0f, 100.0f, { 255, 0, 0, 255 });

	m_gfx->Present();
}

void homer::Engine::Shutdown()
{
	m_gfx->Shutdown();

	if (m_input != nullptr)
	{
		delete m_input;
		m_input = nullptr;
	}

	if (m_gfx != nullptr)
	{
		delete m_gfx;
		m_gfx = nullptr;
	}

	if(m_logger != nullptr)
	{
		delete m_logger;
		m_logger = nullptr;
	}
}

void homer::Engine::Exit()
{
	m_isRunning = false;
}
