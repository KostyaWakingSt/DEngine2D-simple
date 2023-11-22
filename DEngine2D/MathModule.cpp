#include "MathModule.h"

const sf::Vector2f& VectorMath::VectorCollection::getStartPoint() const {
    return m_start;
}

const sf::Vector2f& VectorMath::VectorCollection::getEndPoint() const {
    return m_end;
}

VectorMath::VectorCollection::VectorCollection(const sf::Vector2f start, const sf::Vector2f end) {
    m_start = start;
    m_end = end;
}

float VectorMath::getVector2fLength(const sf::Vector2f& vector) {
    return sqrtf((vector.x * vector.x) + (vector.y * vector.y));
}

//vector math methods
bool VectorMath::isVectorIntersect(const VectorCollection& a, const VectorCollection& b) {
    sf::Vector2f aStartPoint = a.getStartPoint();
    sf::Vector2f bStartPoint = b.getStartPoint();
    sf::Vector2f aEndPoint = a.getEndPoint();
    sf::Vector2f bEndPoint = b.getEndPoint();

    float t = (((aStartPoint.x - bStartPoint.x) * (bStartPoint.y - bEndPoint.y)) - ((aStartPoint.y - bStartPoint.y) * (bStartPoint.x - bEndPoint.x)))
        / (((aStartPoint.x - aEndPoint.x) * (bStartPoint.y - bEndPoint.y)) - ((aStartPoint.y - aEndPoint.y) * (bStartPoint.x - bEndPoint.x)));

    float u = (((aStartPoint.x - bStartPoint.x) * (aStartPoint.y - aEndPoint.y)) - ((aStartPoint.y - bStartPoint.y) * (aStartPoint.x - aEndPoint.x)))
        / (((aStartPoint.x - aEndPoint.x) * (bStartPoint.y - bEndPoint.y)) - ((aStartPoint.y - aEndPoint.y) * (bStartPoint.x - bEndPoint.x)));

    if (t >= 0 && u > 0 && t <= 1 && u <= 1)
        return true;
    else
        return false;
}

sf::Vector2f VectorMath::normalizeVector2f(const sf::Vector2f& vector) {
    float vecLen = getVector2fLength(vector);

    if (vecLen == 0)
        return sf::Vector2f(0, 0);

    return sf::Vector2f(vector.x / vecLen, vector.y / vecLen);
}