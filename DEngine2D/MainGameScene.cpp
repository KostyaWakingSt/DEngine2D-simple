#include "MainGameScene.h"
#include <iostream>

void initMainScene(SceneEntity* const& scene, sf::RenderWindow* const& renderWindow) {
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {

			sf::RectangleShape shape{sf::Vector2f(SCALE_WIDTH, SCALE_HEIGHT)};

			//sf::FloatRect textRect = shape.getLocalBounds();
			//shape.setOrigin(textRect.left + textRect.width / 2.0f,
			//	textRect.top + textRect.height / 2.0f);

			shape.setPosition(sf::Vector2f(x * SPACING, y * SPACING));
			//shape.setFillColor(sf::Color(255/(x+1), 255/(y+1), 255/(x+y+1), 255));
			shape.setFillColor(sf::Color::Black);

			SceneObject gridCell{};
			gridCell.setName("grid_obj" + std::to_string((x + y)));
			gridCell.addComponent<RendererComponent>();
			gridCell.getComponent<RendererComponent>()->setTarget(shape);
			gridCell.getComponent<RendererComponent>()->setWindow(renderWindow);
			gridCell.addComponent<MouseEnterEffect>();
			gridCell.getComponent<MouseEnterEffect>()->setRendererComponent(gridCell.getComponent<RendererComponent>());
			gridCell.getComponent<MouseEnterEffect>()->setWindow(renderWindow);

			scene->addObject(gridCell);
		}
	}
}