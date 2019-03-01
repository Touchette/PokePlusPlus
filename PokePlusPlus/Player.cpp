#include "Player.h"
#include "Keys.h"
#include <iostream>

Player::Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed) : animation(texture, imageCount, switchTime) {
	this->speed = speed;
	row = 0;
	
	// Draw the player
	body.setSize(sf::Vector2f(14.0f, 20.0f));
	body.setTexture(texture);
	body.setPosition(480 / 2, 416 / 2);
}


Player::~Player() {
	// Empty destructor
}

void Player::Update(float deltaTime) {
	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(keyW)) {
		movement.y -= speed * deltaTime;
		lastKey = keyW;
		idle = false;
	}
	if (sf::Keyboard::isKeyPressed(keyA)) {
		movement.x -= speed * deltaTime;
		lastKey = keyA;
		idle = false;
	}
	if (sf::Keyboard::isKeyPressed(keyS)) {
		movement.y += speed * deltaTime;
		lastKey = keyS;
		idle = false;
	}
	if (sf::Keyboard::isKeyPressed(keyD)) {
		movement.x += speed * deltaTime;
		lastKey = keyD;
		idle = false;
	}

	// Check for idle animation
	if (movement.x == 0.0f) {
		if (lastRow) {
			row = lastRow;
		}
		else {
			row = 0;
		}
		idle = true;
	}
	if (lastKey == keyW) {
		row, lastRow = 2;
	}
	if (lastKey == keyA) {
		row, lastRow = 3;
	}
	if (lastKey == keyS) {
		row, lastRow = 0;
	}
	if (lastKey == keyD) {
		row, lastRow = 1;
	}

	animation.Update(row, deltaTime, idle);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}

void Player::Draw(sf::RenderWindow &window) {
	window.draw(body);
}
