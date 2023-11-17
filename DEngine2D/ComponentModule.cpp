#include "ComponentModule.h"
#include <iostream>

void RendererComponent::setWindow(sf::RenderWindow* const& renderWindow) {
	m_renderWindow = renderWindow;
}

sf::Drawable* RendererComponent::getTarget() const {
	return m_target;
}

sf::Shape* RendererComponent::getShapeFromTarget() const {
	return static_cast<sf::Shape*>(m_target);
}

sf::RenderWindow* RendererComponent::getWindow() const {
	return m_renderWindow;
}

void RendererComponent::initialize() { }

void RendererComponent::update() { 
	if (m_renderWindow && m_target) { 
		m_renderWindow->draw(*m_target);
	}
}

void MouseEnterEffect::initialize() { }

void MouseEnterEffect::update() {
	if (!m_renderer || !m_window || !sf::Mouse::isButtonPressed(sf::Mouse::Left)) return;

	sf::Vector2f mouseWorld = m_window->mapPixelToCoords(sf::Mouse::getPosition(*m_window));

	if (m_renderer->getShapeFromTarget()->getGlobalBounds().contains(mouseWorld)) {
		m_renderer->getShapeFromTarget()->setFillColor(sf::Color::Green);
	}
}

void MouseEnterEffect::setRendererComponent(RendererComponent* const& renderer) {
	m_renderer = renderer;
	m_oldColor = renderer->getShapeFromTarget()->getFillColor();
}

void MouseEnterEffect::setWindow(sf::RenderWindow* const& renderer) {
	m_window = renderer;
}

void TransformComponent::setTarget(sf::Transformable* const& target) {
	m_target = target;
}

sf::Transformable* TransformComponent::getTransform() {
	return m_target;
}

void TransformComponent::update() { }
void TransformComponent::initialize() { }