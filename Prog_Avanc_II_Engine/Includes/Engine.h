#pragma once
#include "IGfx.h"
#include "IInput.h"
#include "ILogger.h"

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
		IGfx* Gfx() { return m_gfx; }; // A faire pour ISFX
		IInput* Input() { return m_input; };
	private:
		Engine() = default;
		void ProcessInput();
		void Update(float dt);
		void Render();
	private:
		IGfx* m_gfx = nullptr;
		IInput* m_input = nullptr;
		ILogger* m_logger = nullptr;
		ILogger* m_filelog = nullptr;
		bool m_isRunning = false;
		bool m_isInit = false;
		float m_rectX = 0.0f;
		float m_rectY = 0.0f;
		float m_rectSpeed = 100.0f;
		float m_deltaTime = 0.0f;
	protected:
		friend class SdlInput;
		void Shutdown();
		void Exit();
	};
}