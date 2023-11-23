#include "BaseEngineComponents.h"

using namespace EngineComponent;
extern sf::RenderWindow* global_window;
extern SceneManager global_sceneManager;

/////////////////////////////////////////////////////////////

sf::Drawable* RendererComponent::getTarget() const {
    return m_target;
}

sf::Shape* RendererComponent::getShapeFromTarget() const {
    return static_cast<sf::Shape*>(m_target);
}

void RendererComponent::initialize() { }

void RendererComponent::update() {
    if (m_target) {
        global_window->draw(*m_target);
    }
}

void RendererComponent::setTexture(const sf::Texture& sprite) {
    if (auto* shape = getShapeFromTarget()) {
        shape->setTexture(&sprite);
    }
}

void RendererComponent::setTextureFromFile(const std::string& path) {
    if (auto* shape = getShapeFromTarget()) {
        sf::Texture* texToLoad = new sf::Texture();
        
        if (texToLoad->loadFromFile(path)) {
            shape->setTexture(texToLoad);
        }
    }
}

void TransformComponent::setTarget(sf::Transformable* const& target) {
    m_target = target;
}

sf::Transformable* TransformComponent::getTransform() {
    return m_target;
}

void TransformComponent::update() { }
void TransformComponent::initialize() { }