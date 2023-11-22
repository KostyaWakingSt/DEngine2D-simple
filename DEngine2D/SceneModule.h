#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <vector>
#include "ComponentModule.h"

namespace EngineScene {
	class SceneObject : public IUpdatable {
	public:
		std::string getName() const;
		void setName(const std::string name);

		template<class T = Component>
		void addComponent() {
			std::shared_ptr<Component> component{new T()};
			component->initialize();

			m_components.push_back(component);
		}

		template<class T = Component>
		T* getComponent() {
			T* output = nullptr;

			for (auto& component : m_components) {
				if (T* ptr = dynamic_cast<T*>(component.get())) {
					output = ptr;
				}
			}

			return output;
		}

		template<class T = Component>
		void removeComponent() {
			std::shared_ptr<T> output = nullptr;

			for (auto& component : m_components) {
				if (T* ptr = dynamic_cast<T*>(component.get())) {
					output = component;
				}
			}

			m_components.remove(output);
		}

		void update(const float deltaTime);

		SceneObject(const std::string name);
		SceneObject();
	private:
		std::list<std::shared_ptr<Component>> m_components;
		std::string m_name = "unnamed";
	};


	class SceneEntity : public IUpdatable {
	public:
		SceneObject* findObjectByName(const std::string name, const bool& first = true);
		std::list<std::shared_ptr<SceneObject>> getAllObjectsOnScene() const;

		void initialize();
		void setInitFunc(void(*initFunc)(SceneEntity* const&));

		void update(const float deltaTime);
		void addObject(SceneObject& const obj);
		void removeObject(SceneObject* const& obj);

		static SceneObject* findInActiveScene(const std::string name);
	private:
		std::list<std::shared_ptr<SceneObject>> m_objects;
		void(*m_initFunc)(SceneEntity* const&);
	};

	class SceneManager : public IUpdatable {
	public:
		void update(const float deltaTime);

		void addScene(const SceneEntity& scene);
		void removeScene(const int sceneIndex);

		void setScene(const int index);
		void initialize(const int startSceneIndex);

		const SceneEntity& getActiveScene() const;
	private:
		SceneEntity* m_currentScene = nullptr;
		std::vector<SceneEntity> m_scenes;
	};
}