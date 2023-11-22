#include "PhysicModule.h"
#include "MathModule.h"

//--------------BOX_COLLIDER--------------
void BoxColliderComponent::initialize() { }
void BoxColliderComponent::update(const float deltaTime) { }

void BoxColliderComponent::setSize(sf::Vector2f* const& size) {
    m_size = sf::Vector2f(size->x/2, size->y/2);
}

void BoxColliderComponent::setOffset(sf::Vector2f* const& offset) {
    m_offset = *offset;
}

void BoxColliderComponent::setTarget(sf::Transformable* const& target) {
    m_target = target;
}

std::vector<sf::Vector2f> BoxColliderComponent::getVertices() const {
    std::vector<sf::Vector2f> output{};

    if (m_target) {
        sf::Vector2f position = m_target->getPosition();

        output.push_back(sf::Vector2f{ position.x - m_size.x + m_offset.x, position.y - m_size.y + m_offset.y });
        output.push_back(sf::Vector2f{ position.x - m_size.x + m_offset.x, position.y + m_size.y + m_offset.y });
        output.push_back(sf::Vector2f{ position.x + m_size.x + m_offset.x, position.y + m_size.y + m_offset.y });
        output.push_back(sf::Vector2f{ position.x + m_size.x + m_offset.x, position.y - m_size.y + m_offset.y });

        return output;
    }
    else return output;
}

bool BoxCastComponent::isIntersectColliders(const BoxColliderComponent& a, const BoxColliderComponent& b) {
    for (int i = 0; i < a.getVertices().size() - 1; i++)
    {
        for (int j = 0; j < b.getVertices().size() - 1; j++)
        {
            VectorMath::VectorCollection aCollection{a.getVertices()[i], a.getVertices()[i+1]};
            VectorMath::VectorCollection bCollection{b.getVertices()[j], b.getVertices()[j + 1]};

            if (VectorMath::isVectorIntersect(aCollection, bCollection))
                return true;
        }
    }

    return false;
}

void BoxCastComponent::addColliderObject(BoxColliderComponent* const& collider) {
    m_colliders.push_back(collider);
}

void BoxCastComponent::initialize() { }

void BoxCastComponent::update(const float deltaTime) {
    for(auto& collider : m_colliders)
    {
        for (auto& colliderTwo : m_colliders)
        {
            if (collider == colliderTwo)
                continue;
            
            if (isIntersectColliders(*collider, *colliderTwo))
                m_onIntersect.invoke(collider, colliderTwo);
        }
    }
}

Action<BoxColliderComponent*, BoxColliderComponent*>* BoxCastComponent::getIntersectEvent() {
    return &m_onIntersect;
}

