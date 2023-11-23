#include "Engine.h"
#include "GameSourceData.h"

extern EngineScene::SceneManager global_sceneManager;
extern sf::RenderWindow* global_window;
extern GameEventHandler global_eventHandler;
extern GameTime global_time;
extern Coroutine global_coroutine;

void Engine::Run()
{
	global_window = new sf::RenderWindow(sf::VideoMode(RESOLUTION_X, RESOLUTION_Y), APP_NAME);

	//events
	*global_eventHandler.getBeforeUpdateEvent() += []() -> void { global_window->clear(sf::Color::Black); };
	*global_eventHandler.getAfterUpdateEvent() += []() -> void { global_window->display(); };

	//TEST_SHOW_FPS
	*global_eventHandler.getBeforeUpdateEvent() += []() -> void {
		if (int(global_time.getCurrentTime()) % 2 == 0) {
			global_window->setTitle(APP_NAME + '\t' + std::to_string(int(1 / global_time.getDeltaTime())));
		}
	};
	//end events
	
	sf::Clock clock;
	while (global_window->isOpen())
	{
		sf::Event event;
		while (global_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				*global_eventHandler.getBeforeUpdateEvent() -= []() -> void { global_window->clear(sf::Color::Black); };
				*global_eventHandler.getAfterUpdateEvent() -= []() -> void { global_window->display(); };

				global_window->close();
			}
		}

		global_time.updateTime(clock.restart().asSeconds());
		global_coroutine.updateCoroutine(global_time.getCurrentTime());

		global_eventHandler.getBeforeUpdateEvent()->invoke();
		global_sceneManager.update();
		global_eventHandler.getAfterUpdateEvent()->invoke();
	}
}