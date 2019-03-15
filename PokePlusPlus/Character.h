#pragma once

#ifndef CHARACTER_H
#define CHARACTER_h

#include <SFML\Graphics.hpp>
#include "Constants.h"
#include "Animation.h"

class Character {
  // +------------------+
  // | Public functions |
  // +------------------+
  public:
	// =========================+
	// Constructor & Destructor |
	// =========================+
	Character(sf::Texture *texture, sf::Vector2u imageCount);
	virtual ~Character();

	// ======================+
	// Drawing               |
	// ======================+
	// Will make our movement calls and update the sprite's last position
	// before doing so in case we need to cancelMovement()
	void update();
	// Duh
	void draw(sf::RenderWindow &window);

	// ======================+
	// Moving                |
	// ======================+
	// Will check if we're turning the character or not,
	// will also update if we've started movement (which we have
	// if this function is being called)
	void startMovement(Direction direction);
	// Actually move the character in a certain direction, or step
	// in a direction if turning to a new direction
	void move(Direction direction);
	// Cancel our movement if we've collided with an object we cannot
	// pass
	void cancelMovement() { body.setPosition(lastPosition); };

	// ======================+
	// Misc                  |
	// ======================+
	sf::Vector2f getPosition() { return body.getPosition(); };

  // +---------------------+
  // | Protected variables |
  // +---------------------+
  protected:
	  // All character sprites have this width and height
	  const float width  = 14.0f;
	  const float height = 20.0f;

	  // Actual character to apply textures to
	  sf::RectangleShape body;

	  // If moving is true we continue stepping in the current direction,
	  // if turning is true then we simply swap the direction we're facing
	  bool moving, turning;
	  Direction direction;
	  sf::Vector2f lastPosition;
	  int moveCounter = 0;

	  // Our animations are handled in the animation class, but we must keep
	  // track of the frames we're on for movement purposes
	  Animation animation;
	  int stepType = leftFoot;
};

#endif
