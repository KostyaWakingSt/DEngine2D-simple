#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "ComponentModule.h"
#include "SceneModule.h"
#include "MainGameScene.h"
#include "ScenePhysicTest.h"
#include "MenuScene.h"
#include "GameSourceData.h"

extern SceneManager global_sceneManager;
extern sf::RenderWindow* global_window;

int main()
{
	global_window = new sf::RenderWindow(sf::VideoMode(1280, 720), "game");

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

	//SceneManager sceneManager{};
	//sceneManager.addScene(physicScene);
	global_sceneManager.addScene(menuScene);
	global_sceneManager.addScene(mainScene);
	global_sceneManager.initialize(0);

	sf::Clock clock;
	while (global_window->isOpen())
	{
		sf::Event event;
		while (global_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				global_window->close();
		}

		float delta = clock.restart().asSeconds();

		global_window->clear(sf::Color::Black);

		//update scenes
		global_sceneManager.update(delta);
		//end update

		global_window->display();
	}
}
