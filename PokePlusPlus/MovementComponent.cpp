#include "MovementComponent.h"


// +--------------------------+
// | Constructor / Destructor |
// +--------------------------+
MovementComponent::MovementComponent(sf::Sprite &sprite, float maxVelocity) : sprite(sprite) {
	this->maxVelocity = maxVelocity;
}


MovementComponent::~MovementComponent() {
	//
}


// +-----------+
// | Functions |
// +-----------+
void MovementComponent::move(const float dir_x, const float dir_y, const float &dt) {
	this->velocity.x = this->maxVelocity * dir_x;
	this->velocity.y = this->maxVelocity * dir_y;

	this->sprite.move(this->velocity * dt);
}

void MovementComponent::update(const float &dt) {
	//
}

// +-------------------+
// | Getters & Setters |
// +-------------------+
const sf::Vector2f &MovementComponent::getVelocity() const {
	return this->velocity;
}


// +--------------+
// | Initializers |
// +--------------+
void MovementComponent::initVariables() {
	//
}