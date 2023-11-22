#include "UIComponentModule.h"
#include "BaseEngineComponents.h"

using namespace EngineComponent;
extern sf::RenderWindow* global_window;

void ImageComponent::initialize() { }
void ImageComponent::update(const float deltaTime) { }

void ImageComponent::setRenderer(RendererComponent* const& renderer) {
	m_renderer = renderer;
}

void ImageComponent::setSizeX(float X, bool scaleX) {
	if (!m_renderer) return;

	sf::Shape* shape = m_renderer->getShapeFromTarget();

	if (scaleX)
		shape->setScale(sf::Vector2f(global_window->getSize().x - X / shape->getLocalBounds().width, shape->getScale().y));
	else
		shape->setScale(sf::Vector2f(X / shape->getLocalBounds().width, shape->getScale().y));
}

void ImageComponent::setSizeY(float Y, bool scaleY) {
	if (!m_renderer) return;

	sf::Shape* shape = m_renderer->getShapeFromTarget();

	if (scaleY)
		shape->setScale(sf::Vector2f(shape->getScale().x, global_window->getSize().y - Y / shape->getLocalBounds().height));
	else
		shape->setScale(sf::Vector2f(shape->getScale().x, Y / shape->getLocalBounds().height));
}