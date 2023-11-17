#pragma once

#include <SFML/Graphics.hpp>
#include "ComponentModule.h"
#include "SceneModule.h"
#include <list>
#include <vector>
#include "BaseModule.h"

static class VectorMath {
public:
	class VectorCollection {
	public:
		const sf::Vector2f& getStartPoint() const;
		const sf::Vector2f& getEndPoint() const;

		VectorCollection(const sf::Vector2f start, const sf::Vector2f end);
	private:
		sf::Vector2f m_start;
		sf::Vector2f m_end;
	};

	static bool isVectorIntersect(VectorCollection* const& a, VectorCollection* const& b);
};

class BoxColliderComponent : public Component {
public:
	void update() override;
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
	void update() override;
	void initialize() override;

	void addColliderObject(BoxColliderComponent* const& collider);
	Action<BoxColliderComponent*, BoxColliderComponent*>* getIntersectEvent();
private:
	bool isIntersectColliders(BoxColliderComponent* const& a, BoxColliderComponent* const& b);

	std::list<BoxColliderComponent*> m_colliders;
	Action<BoxColliderComponent*, BoxColliderComponent*> m_onIntersect;
};

//------TEST_CLASS------
class MovementComponent : public Component {
public:
	void update() override;
	void initialize() override;

	void setTarget(TransformComponent* const& target);
private:
	TransformComponent* m_transform;
};
