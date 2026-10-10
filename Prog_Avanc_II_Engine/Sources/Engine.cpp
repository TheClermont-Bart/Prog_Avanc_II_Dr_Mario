#include "Engine.h"
#include "SDLGfx.h"
#include "SdlInput.h"
#include "SdlSfx.h"
#include "World.h"
#include <Windows.h>
#include <ctime>

#ifdef _DEBUG
#include "Console_Log.h"
#else
#include "File_Log.h"
#endif 


bool homer::Engine::Init(const char* title, int width, int height)
{
	m_gfx = new SdlGfx();
	m_input = new SdlInput();
	m_sound = new SdlSfx();
	m_world = new homer::World();

	m_windowHeight = height;
	m_windowWidth = width;

	#ifdef _DEBUG
		m_logger = new Console_Log();
	#else
		m_logger = new File_Log();
	#endif 

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
}

void homer::Engine::Update(float dt)
{
	m_world->Update(dt);
}

void homer::Engine::Render()
{
	m_gfx->SetColor({ 0, 0, 0, 255 });
	m_gfx->Clear();

	m_world->Draw();

	m_gfx->Present();
}

void homer::Engine::Shutdown()
{
	if (m_world != nullptr)
	{
		delete m_world;
		m_world = nullptr;
	}

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

	if(m_sound != nullptr)
	{
		delete m_sound;
		m_sound = nullptr;
	}

}

void homer::Engine::Exit()
{
	m_isRunning = false;
}
