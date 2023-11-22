#include "ScenePhysicTest.h"
#include "BaseEngineComponents.h"

using namespace EngineComponent;

void printIntersect(BoxColliderComponent* a, BoxColliderComponent* b) {
	std::cout << "COLLIDER: INTERSECT" << std::endl;
}

void initPhysicTestScene(SceneEntity* const& scene) {
	//sf::View view{renderWindow->getDefaultView()};
	//renderWindow->setView(view);

	//sf::RectangleShape oneShape{sf::Vector2f(SCALE, SCALE)};
	//sf::RectangleShape twoShape{sf::Vector2f(SCALE, SCALE)};

	//oneShape.setOrigin(sf::Vector2f(oneShape.getSize().x / 2, oneShape.getSize().y / 2));
	//twoShape.setOrigin(sf::Vector2f(twoShape.getSize().x / 2, twoShape.getSize().y / 2));

	//oneShape.setPosition(sf::Vector2f(100, 100));
	//twoShape.setPosition(sf::Vector2f(300, 100));

	//oneShape.setFillColor(sf::Color::Blue);
	//twoShape.setFillColor(sf::Color::Red);

	//sf::Vector2f size{sf::Vector2f(SCALE, SCALE)};

	//SceneObject oneObj{"oneObj"};
	//oneObj.addComponent<RendererComponent>();
	//oneObj.getComponent<RendererComponent>()->setTarget(oneShape);
	//oneObj.getComponent<RendererComponent>()->setWindow(renderWindow);
	//oneObj.addComponent<BoxColliderComponent>();
	//oneObj.getComponent<BoxColliderComponent>()->setTarget(oneObj.getComponent<RendererComponent>()->getShapeFromTarget());
	//oneObj.getComponent<BoxColliderComponent>()->setSize(&size);
	//oneObj.addComponent<TransformComponent>();
	//oneObj.getComponent<TransformComponent>()->setTarget(oneObj.getComponent<RendererComponent>()->getShapeFromTarget());

	//SceneObject twoObj{};
	//twoObj.addComponent<RendererComponent>();
	//twoObj.getComponent<RendererComponent>()->setTarget(twoShape);
	//twoObj.getComponent<RendererComponent>()->setWindow(renderWindow);
	//twoObj.addComponent<BoxColliderComponent>();
	//twoObj.getComponent<BoxColliderComponent>()->setTarget(twoObj.getComponent<RendererComponent>()->getShapeFromTarget());
	//twoObj.getComponent<BoxColliderComponent>()->setSize(&size);
	//twoObj.addComponent<TransformComponent>();
	//twoObj.getComponent<TransformComponent>()->setTarget(twoObj.getComponent<RendererComponent>()->getShapeFromTarget());

	//SceneObject boxCastObj{"boxCastObj"};
	//boxCastObj.addComponent<BoxCastComponent>();
	//boxCastObj.getComponent<BoxCastComponent>()->addColliderObject(oneObj.getComponent<BoxColliderComponent>());
	//boxCastObj.getComponent<BoxCastComponent>()->addColliderObject(twoObj.getComponent<BoxColliderComponent>());
	////*boxCastObj.getComponent<BoxCastComponent>()->getIntersectEvent() += printIntersect;

	//SceneObject movementObj{ "movement" };
	////movementObj.addComponent<MovementComponent>();
	////movementObj.getComponent<MovementComponent>()->setTarget(oneObj.getComponent<TransformComponent>());

	////scene->addObject(oneObj);
	////scene->addObject(twoObj);
	////scene->addObject(boxCastObj);
	////scene->addObject(movementObj);
}