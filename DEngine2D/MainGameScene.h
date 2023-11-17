#pragma once

#include "SceneModule.h"

constexpr int WIDTH = 130;
constexpr int HEIGHT = 100;
constexpr float SCALE_WIDTH = 10;
constexpr float SCALE_HEIGHT = 10;
constexpr float SPACING = 10;

void initMainScene(SceneEntity* const& scene, sf::RenderWindow* const& renderWindow);
