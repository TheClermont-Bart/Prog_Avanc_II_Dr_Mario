#pragma once
#include "IGfx.h"
#include "ISfx.h"
#include "IInput.h"
#include "ILogger.h"
#include "IWorld.h"

class SdlInput;

namespace homer {
	class Engine final {
	public:
		static Engine* Get() {
			static Engine* eng = nullptr;
			if (eng == nullptr) {
				eng = new Engine();
			}
			return eng;
		}
		bool Init(const char* title, int width, int height);
		void Start();
		IGfx* Gfx() { return m_gfx; };
		IInput* Input() { return m_input; };
		ILogger* Logger() { return m_logger; };
		ISfx* Sound() { return m_sound; };
		IWorld* World() { return m_world; };
		int WindowWidth() { return m_windowWidth; };
		int WindowHeight() { return m_windowHeight; };
	private:
		Engine() = default;
		void ProcessInput();
		void Update(float dt);
		void Render();
	private:
		IGfx* m_gfx = nullptr;
		IInput* m_input = nullptr;
		ILogger* m_logger = nullptr;
		ISfx* m_sound = nullptr;
		IWorld* m_world = nullptr;
		bool m_isRunning = false;
		bool m_isInit = false;
		float m_deltaTime = 0.0f;
		int m_windowWidth = 0;
		int m_windowHeight = 0;
	protected:
		friend class SdlInput;
		void Shutdown();
		void Exit();
	};
}