#pragma once

#include "ComponentModule.h"
#include "SceneModule.h"

using namespace EngineScene;

namespace EngineComponent {
	class RendererComponent : public Component {
	public:
		void update(const float deltaTime) override;
		void initialize() override;

		template <typename T = sf::Drawable>
		void setTarget(T& const target) {
			m_target = new T(target);
		}

		sf::Drawable* getTarget() const;
		sf::Shape* getShapeFromTarget() const;

		~RendererComponent() {
			delete m_target;
		}
	private:
		sf::Drawable* m_target;
	};

	class ObjectCreateComponent : public Component {
	public:
		void update(const float deltaTime) override;
		void initialize() override;

		void setSceneTarget(SceneEntity* const& sceneTarget);
		void create(SceneObject& sceneObj);
	private:
		SceneEntity* m_sceneTarget;
	};

	class TransformComponent : public Component {
	public:
		void update(const float deltaTime) override;
		void initialize() override;

		void setTarget(sf::Transformable* const& target);
		sf::Transformable* getTransform();
	private:
		sf::Transformable* m_target;
	};
}