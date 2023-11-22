#pragma once

#include "ComponentModule.h"
#include <SFML/Graphics.hpp>

class Movement : public Component {
public:
	void update(const float deltaTime) override;
	void initialize() override;
};