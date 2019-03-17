#pragma once

#ifndef MOVEMENTCOMPONENT_H
#define MOVEMENTCOMPONENT_H

#include <map>
#include <ctime>
#include <stack>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class MovementComponent {
  public: // functions
	// +--------------------------+
	// | Constructor / Destructor |
	// +--------------------------+
	MovementComponent(sf::Sprite &sprite, float maxVelocity);
	virtual ~MovementComponent();

	// +-----------+
	// | Functions |
	// +-----------+
	void move(const float dir_x, const float dir_y, const float &dt);
	void update(const float &dt);

	// +-------------------+
	// | Getters & Setters |
	// +-------------------+
	const sf::Vector2f &getVelocity() const;

  private:
	// +--------------+
	// | Initializers |
	// +--------------+
	void initVariables();

  private: // variables
	  sf::Sprite &sprite;

	  float maxVelocity;
	  sf::Vector2f velocity;
	  sf::Vector2f acceleration;
	  sf::Vector2f deceleration;
};

#endif
