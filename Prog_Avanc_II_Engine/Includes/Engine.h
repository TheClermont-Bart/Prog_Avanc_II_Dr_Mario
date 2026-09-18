#pragma once
#include "IGfx.h"
#include "IInput.h"

namespace homer {
	class Engine final {
	public:
		bool Init(const char* title, int width, int height);
		void Start();
	private:
		void ProcessInput();
		void Update(float dt);
		void Render();
		void Shutdown();
		void Exit();
	private:
		IGfx* m_gfx;
		IInput* m_input;
		bool m_isRunning = false;
		bool m_isInit = false;
		float m_rectX = 0.0f;
		float m_rectY = 0.0f;
		float m_rectSpeed = 100.0f;
		float m_deltaTime = 0.0f;
	};
}