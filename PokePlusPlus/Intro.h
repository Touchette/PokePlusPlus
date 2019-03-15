#pragma once

#ifndef INTRO_H
#define INTRO_H

#include <SFML\Graphics.hpp>
#include <Thor\Animations.hpp>
#include "Constants.h"
#include "Animation.h"

class Intro {
	// +------------------+
	// | Public functions |
	// +------------------+
  public:
	// =========================+
	// Constructor & Destructor |
	// =========================+
	Intro();
	virtual ~Intro();

	void play(sf::RenderWindow &window);
	void update(float deltaTime);

	// +------------------+
	// | Public variables |
	// +------------------+
  public:
	bool played = false;
	// Animations
	Animation copyrightAnim;
	Animation gameFreakLogoAnim;
	Animation gameFreakStarsAnim;
	Animation introFightAnim;
	Animation titleScreenAnim;
	// +-------------------+
	// | Private variables |
	// +-------------------+
  private:
	// We need to know how many images we have, as well
	// as which image we're currently on
	const float height = 144.0f;
	const float width = 160.0f;
	sf::RectangleShape screen;
};

#endif