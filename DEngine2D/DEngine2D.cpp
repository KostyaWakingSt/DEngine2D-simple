#include "Engine.h"
#include "MainGameScene.h"
#include "ScenePhysicTest.h"
#include "MenuScene.h"

extern SceneManager global_sceneManager;

int main()
{
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

	global_sceneManager.addScene(menuScene);
	global_sceneManager.addScene(mainScene);
	global_sceneManager.initialize(0);

	Engine::Run();
}
