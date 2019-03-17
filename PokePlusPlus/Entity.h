#pragma once

#ifndef ENTITY_H
#define ENTITY_H

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

class Entity {
  public: // functions
	// +--------------------------+
	// | Constructor / Destructor |
	// +--------------------------+
	Entity();
	virtual ~Entity();

	// +---------------------+
	// | Component Functions |
	// +---------------------+
	void createSpite(sf::Texture *texture);

	// +-----------+
	// | Functions |
	// +-----------+
	virtual void move(const float &dt, const float dir_x, const float dir_y);
	 
	virtual void update(const float &dt);
	virtual void render(sf::RenderTarget *target);

  private: // functions
	// +--------------+
	// | Initializers |
	// +--------------+
	void initVariables();

  protected: // variables
	sf::Texture *texture;
	sf::Sprite* sprite;

	float movementSpeed;
};

#endif
