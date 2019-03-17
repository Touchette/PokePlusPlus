#include "Entity.h"


Entity::Entity() {
	// Initializing the entity to a white rectangle... for now, eventually there
	// will be both NPCs and the Player which inherit from this class
	this->initVariables();
}


Entity::~Entity() {
	delete this->sprite;
}


// +---------------------+
// | Component Functions |
// +---------------------+
void Entity::createSpite(sf::Texture * texture) {
	this->texture = texture;
	this->sprite->setTexture(*this->texture);
}


// +-----------+
// | Functions |
// +-----------+
void Entity::move(const float &dt, const float dir_x, const float dir_y) {
	// Every entity can move at a certain base speed
	if (this->sprite) {
		this->sprite->move(dir_x * this->movementSpeed, dir_y * this->movementSpeed);
	}
}

void Entity::update(const float & dt) {
	//
}

void Entity::render(sf::RenderTarget *target) {
	if (this->sprite) {
		target->draw(*this->sprite);
	}
}


// +--------------+
// | Initializers |
// +--------------+
void Entity::initVariables() {
	this->texture = nullptr;
	this->sprite = nullptr;
	this->movementSpeed = 50.0f;
}
