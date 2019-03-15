#pragma once

#include <iostream>
#include "Player.h"

Player::Player(sf::Texture *texture, sf::Vector2u imageCount) : Character(texture, imageCount) {
	// Empty constructor
}

Player::~Player() {
	// Empty destructor
}

void Player::update() {
	if (moving) {
		Character::update();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		startMovement(up);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		startMovement(left);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		startMovement(down);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		startMovement(right);
	}
}
