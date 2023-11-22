#include "MenuSceneComponents.h"
#include "SceneModule.h"
#include "BaseEngineComponents.h"

extern EngineScene::SceneManager global_sceneManager;

void Movement::initialize() { }

void Movement::update(const float deltaTime) {
	EngineScene::SceneObject* target = EngineScene::SceneEntity::findInActiveScene("Player");

	if (!target) return;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		target->getComponent<EngineComponent::TransformComponent>()->getTransform()->move(sf::Vector2f(0, .1));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		target->getComponent<EngineComponent::TransformComponent>()->getTransform()->move(sf::Vector2f(0, -.1));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		target->getComponent<EngineComponent::TransformComponent>()->getTransform()->move(sf::Vector2f(-.1, 0));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		target->getComponent<EngineComponent::TransformComponent>()->getTransform()->move(sf::Vector2f(.1, 0));
}