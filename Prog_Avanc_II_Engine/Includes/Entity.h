#pragma once 
#include <string>
#include "Component.h"
#include "IUpdateable.h"
#include "IDrawable.h"
#include <unordered_map>
#include <typeinfo>

namespace homer
{
	class Entity final
	{
	public:
		Entity(const std::string& name) : m_name(name) {};
		virtual ~Entity() = default;

		virtual void Start() {};

		virtual void Update(float deltaTime) 
		{
			for (auto i = m_ComponentMap.find(Component))
			{

			}
		};

		virtual void Draw() 
		{
			for (int i = 0; i < m_Updateables.size(); i++)
			{
		
			}
		};

		void AddComponent(Component* cmp)
		{
			const type_info* type = &typeid(*cmp);
			m_ComponentMap.emplace(type, cmp);
		};
		
		virtual void Destroy() {};
		std::string& GetName() { return m_name; };

	private:
		std::string m_name;
		std::unordered_map<Component, std::string> m_ComponentMap;
	};
}