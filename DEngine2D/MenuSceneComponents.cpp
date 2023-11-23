#include "MenuSceneComponents.h"
#include "SceneModule.h"
#include "BaseEngineComponents.h"
#include "BaseModule.h"

using namespace EngineComponent;

extern EngineScene::SceneManager global_sceneManager;
extern GameTime global_time;
extern Coroutine global_coroutine;

void Movement::initialize() { }

void Movement::update() {
	EngineScene::SceneObject* target = EngineScene::SceneEntity::findInActiveScene("Player");

	if (!target) return;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		target->getComponent<TransformComponent>()->getTransform()->move(sf::Vector2f(0, 200) * global_time.getDeltaTime());

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		target->getComponent<TransformComponent>()->getTransform()->move(sf::Vector2f(0, -200) * global_time.getDeltaTime());

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		target->getComponent<TransformComponent>()->getTransform()->move(sf::Vector2f(-200, 0) * global_time.getDeltaTime());

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		target->getComponent<TransformComponent>()->getTransform()->move(sf::Vector2f(200, 0) * global_time.getDeltaTime());
}

void Animation::update() { }
void Animation::initialize() { }

void Animation::setChangeStep(float step) {
	m_changeStep = step;
}

void Animation::setTarget(RendererComponent* const& target) {
	m_target = target;
}

void Animation::addTexture(sf::Texture* const& texture) {
	m_textures.push_back(texture);
}

void Animation::animate() {
	if (m_textures.empty())
		return;

	m_target->setTexture(*m_textures[m_currentAnimState]);

	m_currentAnimState++;

	if (m_currentAnimState >= m_textures.size())
		m_currentAnimState = 0;

	global_coroutine.addCoroutine(m_changeStep, [this]() -> void { this->animate(); });
}