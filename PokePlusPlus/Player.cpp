#include "Player.h"


// +--------------------------+
// | Constructor / Destructor |
// +--------------------------+
Player::Player(float x, float y, sf::Texture *texture) {
	// Initializxe base entity data members
	this->initVariables();
	this->initComponents();

	// Make the sprite and place it
	this->createSprite(texture);
	this->setPosition(x, y);
}


Player::~Player() {
	//
}


// +--------------+
// | Initializers |
// +--------------+
void Player::initVariables() {
	//
}

void Player::initComponents() {
	//
}
