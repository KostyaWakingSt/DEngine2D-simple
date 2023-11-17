#include "PhysicModule.h"

//--------------VECTOR_MATH--------------
//vector collection
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

//vector math methods
bool VectorMath::isVectorIntersect(VectorCollection* const& a, VectorCollection* const& b) {
    sf::Vector2f aStartPoint = a->getStartPoint();
    sf::Vector2f bStartPoint = b->getStartPoint();
    sf::Vector2f aEndPoint = a->getEndPoint();
    sf::Vector2f bEndPoint = b->getEndPoint();

    float t = (((aStartPoint.x - bStartPoint.x) * (bStartPoint.y - bEndPoint.y)) - ((aStartPoint.y - bStartPoint.y) * (bStartPoint.x - bEndPoint.x)))
        / (((aStartPoint.x - aEndPoint.x) * (bStartPoint.y - bEndPoint.y)) - ((aStartPoint.y - aEndPoint.y) * (bStartPoint.x - bEndPoint.x)));

    float u = (((aStartPoint.x - bStartPoint.x) * (aStartPoint.y - aEndPoint.y)) - ((aStartPoint.y - bStartPoint.y) * (aStartPoint.x - aEndPoint.x)))
        / (((aStartPoint.x - aEndPoint.x) * (bStartPoint.y - bEndPoint.y)) - ((aStartPoint.y - aEndPoint.y) * (bStartPoint.x - bEndPoint.x)));

    if (t >= 0 && u > 0 && t <= 1 && u <= 1)
        return true;
    else
        return false;
}

//--------------BOX_COLLIDER--------------
void BoxColliderComponent::initialize() { }
void BoxColliderComponent::update() { }

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

bool BoxCastComponent::isIntersectColliders(BoxColliderComponent* const& a, BoxColliderComponent* const& b) {
    for (int i = 0; i < a->getVertices().size() - 1; i++)
    {
        for (int j = 0; j < b->getVertices().size() - 1; j++)
        {
            VectorMath::VectorCollection aCollection{a->getVertices()[i], a->getVertices()[i+1]};
            VectorMath::VectorCollection bCollection{b->getVertices()[j], b->getVertices()[j+1]};

            if (VectorMath::isVectorIntersect(&aCollection, &bCollection))
                return true;
        }
    }

    return false;
}

void BoxCastComponent::addColliderObject(BoxColliderComponent* const& collider) {
    m_colliders.push_back(collider);
}

void BoxCastComponent::initialize() { }

void BoxCastComponent::update() {
    for(auto& collider : m_colliders)
    {
        for (auto& colliderTwo : m_colliders)
        {
            if (collider == colliderTwo)
                continue;
            
            if (isIntersectColliders(collider, colliderTwo))
                m_onIntersect.invoke(collider, colliderTwo);
        }
    }
}

Action<BoxColliderComponent*, BoxColliderComponent*>* BoxCastComponent::getIntersectEvent() {
    return &m_onIntersect;
}

void MovementComponent::setTarget(TransformComponent* const& target) {
    m_transform = target;
}

void MovementComponent::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        m_transform->getTransform()->move(sf::Vector2f(.1f, 0));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        m_transform->getTransform()->move(sf::Vector2f(-.1f, 0));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        m_transform->getTransform()->move(sf::Vector2f(0, -.1f));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        m_transform->getTransform()->move(sf::Vector2f(0, .1f));
    }
}

void MovementComponent::initialize() { }