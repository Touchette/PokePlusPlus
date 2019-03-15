#pragma once

#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML\Graphics.hpp>
#include <Thor\Animations.hpp>

class Animation {
  // +------------------+
  // | Public functions |
  // +------------------+
  public:
	// =========================+
	// Constructor & Destructor |
	// =========================+
	Animation() { };
	Animation(sf::Texture *texture, sf::Vector2u imageCount, float switchTime);
	virtual ~Animation();

	// ======================+
	// Updates               |
	// ======================+
	// This will actually set the new UVrect to be used by a character's
	// setTexture or whatever they're doing
	void update(int row, float deltaTime);

  // +------------------+
  // | Public variables |
  // +------------------+
  public:
	// Access to the spritesheet via UV coordinates
	sf::IntRect uvRect;

  // +-------------------+
  // | Private variables |
  // +-------------------+
  private:
	// We need to know how many images we have, as well
	// as which image we're currently on
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
	float switchTime;
	float totalTime;
};

#endif
