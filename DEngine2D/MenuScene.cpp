#include "MenuScene.h"
#include "UIComponentModule.h"

void initMenuScene(SceneEntity* const& scene, sf::RenderWindow* const& renderWindow) {
	sf::RectangleShape headerTop{sf::Vector2f(1, 100)};
	sf::RectangleShape headerLeft{sf::Vector2f(100, 1)};
	headerTop.setFillColor(sf::Color::Green);
	headerLeft.setFillColor(sf::Color::Red);

	SceneObject header{ "header" };
	header.addComponent<RendererComponent>();
	header.addComponent<ImageComponent>();

	header.getComponent<RendererComponent>()->setTarget(headerTop);
	header.getComponent<RendererComponent>()->setWindow(renderWindow);
	header.getComponent<ImageComponent>()->setRenderer(header.getComponent<RendererComponent>());
	header.getComponent<ImageComponent>()->setSizeX(0, true);
	//header.getComponent<ImageComponent>()->setSizeY(0, true);

	SceneObject headerL{ "headerLeft" };
	headerL.addComponent<RendererComponent>();
	headerL.addComponent<ImageComponent>();
	headerL.addComponent<TransformComponent>();

	headerL.getComponent<RendererComponent>()->setTarget(headerLeft);
	headerL.getComponent<RendererComponent>()->setWindow(renderWindow);
	headerL.getComponent<TransformComponent>()->setTarget(headerL.getComponent<RendererComponent>()->getShapeFromTarget());
	headerL.getComponent<ImageComponent>()->setRenderer(headerL.getComponent<RendererComponent>());
	//headerL.getComponent<ImageComponent>()->setSizeX(0, true);
	headerL.getComponent<ImageComponent>()->setSizeY(header.getComponent<RendererComponent>()->getShapeFromTarget()->getLocalBounds().height, true);
	headerL.getComponent<TransformComponent>()->getTransform()->move(sf::Vector2f(0, header.getComponent<RendererComponent>()->getShapeFromTarget()->getLocalBounds().height));

	scene->addObject(header);
	scene->addObject(headerL);
}