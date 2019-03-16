#include "Entity.h"


Entity::Entity() {
	// Initializing the entity to a white rectangle... for now, eventually there
	// will be both NPCs and the Player which inherit from this class
	this->shape.setSize(sf::Vector2f(16.0f, 14.0f));
	this->shape.setFillColor(sf::Color::White);
	this->movementSpeed = 1.0f;
}


Entity::~Entity() {
	//
}

void Entity::move(const float &dt, const float dir_x, const float dir_y) {
	// Every entity can move at a certain base speed
	this->shape.move(dir_x * this->movementSpeed, dir_y * this->movementSpeed);
}

void Entity::update(const float & dt) {
	//
}

void Entity::render(sf::RenderTarget *target) {
	target->draw(this->shape);
}
