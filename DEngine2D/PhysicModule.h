#pragma once

#include <SFML/Graphics.hpp>
#include "ComponentModule.h"
#include "SceneModule.h"
#include <list>
#include <vector>
#include "BaseModule.h"

class BoxColliderComponent : public Component {
public:
	void update(const float deltaTime) override;
	void initialize() override;

	void setTarget(sf::Transformable* const& target);
	void setSize(sf::Vector2f* const& size);
	void setOffset(sf::Vector2f* const& offset);

	std::vector<sf::Vector2f> getVertices() const;
private:
	sf::Transformable* m_target;

	sf::Vector2f m_size{10, 10};
	sf::Vector2f m_offset{0, 0};
};

class BoxCastComponent : public Component {
public:
	void update(const float deltaTime) override;
	void initialize() override;

	void addColliderObject(BoxColliderComponent* const& collider);
	Action<BoxColliderComponent*, BoxColliderComponent*>* getIntersectEvent();
private:
	bool isIntersectColliders(const BoxColliderComponent& a, const BoxColliderComponent& b);

	std::list<BoxColliderComponent*> m_colliders;
	Action<BoxColliderComponent*, BoxColliderComponent*> m_onIntersect;
};
