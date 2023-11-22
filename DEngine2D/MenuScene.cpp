#include "MenuScene.h"
#include "UIComponentModule.h"
#include "MenuSceneComponents.h"

void initMenuScene(SceneEntity* const& scene) {
	sf::RectangleShape shape{sf::Vector2f(100, 100)};

	SceneObject testObj{ "Player" };
	testObj.addComponent<RendererComponent>();
	testObj.getComponent<RendererComponent>()->setTarget(shape);
	testObj.addComponent<TransformComponent>();
	testObj.getComponent<TransformComponent>()->setTarget(testObj.getComponent<RendererComponent>()->getShapeFromTarget());
	testObj.addComponent<Movement>();

	scene->addObject(testObj);
}