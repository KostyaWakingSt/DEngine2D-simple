#include "BaseEngineComponents.h"

using namespace EngineComponent;
extern sf::RenderWindow* global_window;

void ObjectCreateComponent::update(const float deltaTime) { }
void ObjectCreateComponent::initialize() { }

void ObjectCreateComponent::setSceneTarget(SceneEntity* const& sceneTarget) {
	m_sceneTarget = sceneTarget;
}

void ObjectCreateComponent::create(SceneObject& sceneObj) {
	if (m_sceneTarget)
		m_sceneTarget->addObject(sceneObj);
}
/////////////////////////////////////////////////////////////

sf::Drawable* RendererComponent::getTarget() const {
    return m_target;
}

sf::Shape* RendererComponent::getShapeFromTarget() const {
    return static_cast<sf::Shape*>(m_target);
}

void RendererComponent::initialize() { }

void RendererComponent::update(const float deltaTime) {
    if (m_target) {
        global_window->draw(*m_target);
    }
}

void TransformComponent::setTarget(sf::Transformable* const& target) {
    m_target = target;
}

sf::Transformable* TransformComponent::getTransform() {
    return m_target;
}

void TransformComponent::update(const float deltaTime) { }
void TransformComponent::initialize() { }