#include "UIComponentModule.h"

void ImageComponent::initialize() { }
void ImageComponent::update() { }

void ImageComponent::setRenderer(RendererComponent* const& renderer) {
	m_renderer = renderer;
}

void ImageComponent::setSizeX(float X, bool scaleX) {
	if (!m_renderer) return;

	sf::Shape* shape = m_renderer->getShapeFromTarget();

	if (scaleX)
		shape->setScale(sf::Vector2f(m_renderer->getWindow()->getSize().x - X / shape->getLocalBounds().width, shape->getScale().y));
	else
		shape->setScale(sf::Vector2f(X / shape->getLocalBounds().width, shape->getScale().y));
}

void ImageComponent::setSizeY(float Y, bool scaleY) {
	if (!m_renderer) return;

	sf::Shape* shape = m_renderer->getShapeFromTarget();

	if (scaleY)
		shape->setScale(sf::Vector2f(shape->getScale().x, m_renderer->getWindow()->getSize().y - Y / shape->getLocalBounds().height));
	else
		shape->setScale(sf::Vector2f(shape->getScale().x, Y / shape->getLocalBounds().height));
}