#pragma once

namespace homer
{
	class IScene
	{
	public:
		virtual ~IScene() = default;
		virtual void Load() = 0;
		virtual void Draw() = 0;
		virtual void Update(float deltaTime) {}
		virtual void Unload() = 0;
	};
}
