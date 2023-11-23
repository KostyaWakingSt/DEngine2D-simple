#pragma once

#include "ComponentModule.h"
#include "SceneModule.h"

using namespace EngineScene;

namespace EngineComponent {
	class RendererComponent : public Component {
	public:
		void update() override;
		void initialize() override;

		template <typename T = sf::Drawable>
		void setTarget(T& const target) {
			m_target = new T(target);
		}

		void setTexture(const sf::Texture& sprite);
		void setTextureFromFile(const std::string& path);

		sf::Drawable* getTarget() const;
		sf::Shape* getShapeFromTarget() const;

		~RendererComponent() {
			delete m_target;
		}
	private:
		sf::Drawable* m_target;
	};

	class TransformComponent : public Component {
	public:
		void update() override;
		void initialize() override;

		void setTarget(sf::Transformable* const& target);
		sf::Transformable* getTransform();
	private:
		sf::Transformable* m_target;
	};
}