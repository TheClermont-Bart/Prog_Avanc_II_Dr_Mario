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

		template<typename T> T* AddComponent() {
			T* cmp = new T();
			const type_info* type = &typeid(*cmp);
			m_Component.emplace(type,cmp);
			cmp->SetEntity(this);

			if(auto* u = dynamic_cast<IUpdateable*>(cmp))
			{ 
				m_Updateable.push_back(u);
			}

			if (auto* d = dynamic_cast<IDrawable*>(cmp))
			{
				m_Drawable.push_back(d);
			} 
			return cmp;
		};

		template<typename T> T* GetComponent()
		{
			const type_info* type = &typeid(T);

			auto cmp = m_Component.find(type);

			if(cmp == m_Component.end())
			{
				return nullptr;
			}

			return dynamic_cast<T*>(cmp->second);
		}
		
		virtual void Destroy() {};
		std::string& GetName() { return m_name; };
		float x = 100.0f;
		float y = 100.0f;

	private:
		std::string m_name;
		std::unordered_map<const type_info*,Component*> m_Component;
		std::vector<IUpdateable*> m_Updateable;
		std::vector<IDrawable*> m_Drawable;
		
	};
}