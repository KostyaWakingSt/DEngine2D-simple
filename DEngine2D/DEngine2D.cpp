#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "ComponentModule.h"
#include "SceneModule.h"
#include "MainGameScene.h"
#include "ScenePhysicTest.h"
#include "MenuScene.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "game");

	//scene create
	SceneEntity mainScene{};
	SceneEntity physicScene{};
	SceneEntity menuScene{};
	//end create

	//init scenes
	mainScene.setInitFunc(initMainScene);
	physicScene.setInitFunc(initPhysicTestScene);
	menuScene.setInitFunc(initMenuScene);
	//end init

	SceneManager sceneManager{};
	//sceneManager.addScene(physicScene);
	//sceneManager.addScene(mainScene);
	sceneManager.addScene(menuScene);
	sceneManager.initialize(0, &window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
		//	sceneManager.setScene(0);
		//}

		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
		//	sceneManager.setScene(1);
		//}

		window.clear(sf::Color::Black);

		//update scenes
		sceneManager.update();
		//end update

		window.display();
	}
}
