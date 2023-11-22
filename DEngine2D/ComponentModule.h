#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

__interface IUpdatable
{
	void update(const float deltaTime) = 0;
};

class Component : public IUpdatable {
public:
	virtual void update(const float deltaTime) = 0;
	virtual void initialize() = 0;
};