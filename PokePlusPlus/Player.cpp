#include "Player.h"


// +--------------------------+
// | Constructor / Destructor |
// +--------------------------+
Player::Player(float x, float y, sf::Texture &texture) {
	// Initializxe base entity data members
	this->initVariables();
	this->initComponents();

	// Make the sprite and place it
	this->setTexture(texture);
	this->setPosition(x, y);
}

Player::~Player() {
	//
}


// +-----------+
// | Functions |
// +-----------+
void Player::update(const float &dt) {
	if (this->moving) {
		this->move(this->direction);
	}
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
