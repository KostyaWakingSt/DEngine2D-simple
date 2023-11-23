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
	testObj.getComponent<RendererComponent>()->setTextureFromFile("C:\\Users\\defix\\Documents\\gameLogo.png");

	sf::Texture* oneTex = new sf::Texture();
	sf::Texture* twoTex = new sf::Texture();
	sf::Texture* threeTex = new sf::Texture();

	if(oneTex->loadFromFile("resources\\preview.png") &&
		twoTex->loadFromFile("resources\\ui_tic_tac_toe.png") &&
		threeTex->loadFromFile("resources\\map_plan.png")) {
		testObj.addComponent<Animation>();
		testObj.getComponent<Animation>()->addTexture(oneTex);
		testObj.getComponent<Animation>()->addTexture(twoTex);
		testObj.getComponent<Animation>()->addTexture(threeTex);
		testObj.getComponent<Animation>()->setChangeStep(.1f);
		testObj.getComponent<Animation>()->setTarget(testObj.getComponent<RendererComponent>());

		testObj.getComponent<Animation>()->animate();
	}

	scene->addObject(testObj);
}