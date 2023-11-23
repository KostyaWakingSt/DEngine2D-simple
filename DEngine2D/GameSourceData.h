#pragma once

#include "SceneModule.h"
#include "BaseModule.h"

constexpr int RESOLUTION_X = 1280;
constexpr int RESOLUTION_Y = 720;
constexpr const char* APP_NAME = "DEngine2D_Test";

EngineScene::SceneManager global_sceneManager;
sf::RenderWindow* global_window;
GameEventHandler global_eventHandler;
GameTime global_time;
Coroutine global_coroutine;