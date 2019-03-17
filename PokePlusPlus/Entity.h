#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include "MovementComponent.h"

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
	void createSprite(sf::Texture *texture);

	// +-----------+
	// | Functions |
	// +-----------+
	virtual void setPosition(const float x, const float y);
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
