#include "Entity.h"


Entity::Entity() {
	// Initializing the entity to a white rectangle... for now, eventually there
	// will be both NPCs and the Player which inherit from this class
	this->initVariables();
}

Entity::~Entity() {
	//
}


// +---------------------+
// | Component Functions |
// +---------------------+-
void Entity::setTexture(sf::Texture &texture) {
	// This creates the sprite that we will use for this specific entity.
	// For now, it is only a static sprite. In the future, it will need to be
	// animated.
	this->sprite.setTexture(texture);
	this->sprite.setTextureRect(sf::IntRect(16, 0, 16, 14));
}


// +-----------+
// | Functions |
// +-----------+
void Entity::move(MoveDir dir) {
	// Every entity can move, we need to set up the velocity and then moves
	// the sprite
	this->sprite.setTextureRect(sf::IntRect((1 - this->counter) * 16, this->getDirection(dir) * 14, 16, 14));

	this->lastPosition = this->getPosition();
	this->direction = dir;

	float moveStep = 1.5;

	if (!turning) {
		switch (dir) {
			case UP:
				sprite.move(0, -moveStep);
				break;
			case DOWN:
				sprite.move(0, moveStep);
				break;
			case LEFT:
				sprite.move(-moveStep, 0);
				break;
			case RIGHT:
				sprite.move(moveStep, 0);
				break;
		}
	}

	this->movementCounter += 2;
	if (movementCounter >= 16) {
		this->counter = 0;

		this->sprite.setTextureRect(sf::IntRect((1 - this->counter) * 16, this->getDirection(dir) * 14, 16, 14));

		moving = false;
	}
}

void Entity::startMovement(MoveDir dir) {
	if (dir != this->direction) {
		this->turning = true;
		this->counter = 0;
	} else {
		this->turning = false;
		this->counter = this->moveState;
	}
	this->turning = (dir != this->direction);

	this->movementCounter = 0;
	this->direction = dir;

	this->moving = true;
	this->moveState *= -1;

}

void Entity::update(const float &dt) {
	//
}

void Entity::render(sf::RenderTarget *target) {
	// Only draw something if we have a sprite
	target->draw(this->sprite);
}

void Entity::stopMove() {
	this->sprite.setPosition(this->lastPosition);
}


// +-------------------+
// | Getters & Setters |
// +-------------------+
void Entity::setPosition(const float x, const float y) {
	// This will probably be used to set the starting position
	// of the sprite upon loading every new map / zoning into a new
	// location.
	this->sprite.setPosition(x, y);
}

sf::Vector2f Entity::getPosition() {
	return this->sprite.getPosition();
}

int Entity::getDirection(MoveDir dir) {
	switch (dir) {
		case DOWN:
			return 0;
			break;
		case UP:
			return 1;
			break;
		case RIGHT:
			return 2;
			break;
		case LEFT:
			return 3;
			break;
	}
}


// +--------------+
// | Initializers |
// +--------------+
void Entity::initVariables() {
	this->direction = NONE;

	this->moveState = 0;
	this->movementCounter = 0.0f;
	this->counter = 0.0f;
	this->lastPosition = this->getPosition();

	this->turning = false;
	this->moving = false;
}
