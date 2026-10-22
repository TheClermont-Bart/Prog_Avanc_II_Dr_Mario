#pragma once 
#include <string>
#include "Component.h"
#include "IUpdateable.h"
#include "IDrawable.h"
#include <unordered_map>
#include <typeinfo>
#include <vector>

namespace homer
{
	class Entity final
	{
	public:
		Entity(const std::string& name) : m_name(name) {};
		virtual ~Entity() = default;

		virtual void Start() {};

		void Draw()
		{
			for (auto c : m_Drawable)
			{
				c->Draw();
			}
		};

		void Update(float deltaTime) 
		{
			for (auto c : m_Updateable)
			{
				c->Update(deltaTime);
			}
		};

		template <class T>
		class TestComponent : public Component
		{
		public:
			void AddComponent();

		};

		template<Component* C> C AddComponent(C cmp)
		{
			const type_info* type = &typeid(*cmp);
			m_Component.emplace_back(cmp);

			if(auto* u = dynamic_cast<IUpdateable*>(cmp))
			{ 
				m_Updateable.push_back(u);
			}

			if (auto* d = dynamic_cast<IDrawable*>(cmp))
			{
				m_Drawable.push_back(d);
			}

		};
		
		virtual void Destroy() {};
		std::string& GetName() { return m_name; };

	private:
		std::string m_name;
		std::vector<Component*> m_Component;
		std::vector<IUpdateable*> m_Updateable;
		std::vector<IDrawable*> m_Drawable;
		
	};
}