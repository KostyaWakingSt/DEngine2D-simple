#pragma once

#include <SFML/Graphics.hpp>

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

	static float getVector2fLength(const sf::Vector2f& vector);
	static bool isVectorIntersect(const VectorCollection& a, const VectorCollection& b);
	static sf::Vector2f normalizeVector2f(const sf::Vector2f& vector);
};
