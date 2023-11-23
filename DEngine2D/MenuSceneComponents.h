#pragma once

#include "BaseEngineComponents.h"
#include <SFML/Graphics.hpp>

using namespace EngineComponent;

class Movement : public Component {
public:
	void update() override;
	void initialize() override;
};

class Animation : public Component {
public:
	void update() override;
	void initialize() override;

	void setChangeStep(float step);
	void setTarget(RendererComponent* const& target);
	void animate();
	void addTexture(sf::Texture* const& texture);
private:
	RendererComponent* m_target;
	std::vector<sf::Texture*> m_textures;

	float m_changeStep = 2.0f;
	int m_currentAnimState = 0;
};