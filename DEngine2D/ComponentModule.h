#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

__interface IUpdatable
{
	void update() = 0;
};

class Component : public IUpdatable {
public:
	virtual void update() = 0;
	virtual void initialize() = 0;
};

class RendererComponent : public Component {
public:
	void update() override;
	void initialize() override;

	void setWindow(sf::RenderWindow* const& renderWindow);

	template <typename T = sf::Drawable>
	void setTarget(T& const target) {
		m_target = new T(target);
	}

	sf::Drawable* getTarget() const;
	sf::Shape* getShapeFromTarget() const;
	sf::RenderWindow* getWindow() const;

	~RendererComponent() {
		delete m_target;
	}
private:
	sf::RenderWindow* m_renderWindow;
	sf::Drawable* m_target;
};

class MouseEnterEffect : public Component {
public:
	void update() override;
	void initialize() override;
	void setRendererComponent(RendererComponent* const& renderer);
	void setWindow(sf::RenderWindow* const& renderer);

private:
	RendererComponent* m_renderer;
	sf::RenderWindow* m_window;
	sf::Color m_oldColor;
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