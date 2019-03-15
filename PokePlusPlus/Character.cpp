#pragma once

#include <iostream>
#include "Character.h"

// =========================+
// Constructor & Destructor |
// =========================+
Character::Character(sf::Texture *texture, sf::Vector2u imageCount) : animation(texture, imageCount, 0.3f) {
	// The size of our character
	body.setSize(sf::Vector2f(width, height));
	body.setOrigin(body.getSize() / 2.0f);

	// "Update" the animation to get the proper coordinates for the starting idle animation
	// within the sprite sheet
	body.setTexture(texture);
	//animation.update(0, 0);
	body.setTextureRect(animation.uvRect);

	// Position player in the center of the screen (for now)-
	body.setPosition(80.f, 77.f);

	// Initialize the constants
	lastPosition = body.getPosition();
	moving = false; turning = false;
}

Character::~Character() {
	// Empty destructor
}


// ======================+
// Drawing               |
// ======================+
void Character::update() {
	lastPosition = body.getPosition();
	if (moving) {
		move(direction);
	}
}

void Character::draw(sf::RenderWindow &window) {
	window.draw(body);
}


// ======================+
// Moving                |
// ======================+
void Character::startMovement(Direction direction) {
	// Character movement always starts on the left foot
	if (this->direction != direction) {
		turning = true;
	}
	else {
		turning = false;
	}

	moveCounter = 0;

	this->direction = direction;
	moving = true;
}

void Character::move(Direction direction) {
	// We're moving in the same direction, move a tile forward
	// stepType should switch between 1 and 2, this will be used
	// to switch between left & right steps
	//animation.update(stepType, direction); body.setTextureRect(animation.uvRect);

	if (!turning) {
		switch (direction) {
			case up: // 'W' pressed
				body.move(0, -2);
				break;
			case left: // 'A' pressed
				body.move(-2, 0);
				break;
			case down: // 'S' pressed
				body.move(0, 2);
				break;
			case right: // 'D' pressed
				body.move(2, 0);
				break;
		}
	}

	stepType == leftFoot ? stepType += 2 : stepType -= 2;
	moveCounter += 16 / 8;
	if (moveCounter >= 16) {
		stepType = leftFoot;
		//animation.update(idle, direction); body.setTextureRect(animation.uvRect);
		moving = false;
	}
}