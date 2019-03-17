#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include "MovementComponent.h"

enum MoveDir {
	NONE = 0,
	UP,
	DOWN,
	LEFT,
	RIGHT
};

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
	void setTexture(sf::Texture &texture);
	void createMovementComponent(const float maxVelocity);

	// +-----------+
	// | Functions |
	// +-----------+
	virtual void setPosition(const float x, const float y);
	virtual void move(MoveDir dir);
	virtual void startMovement(MoveDir dir);
	 
	virtual void update(const float &dt);
	virtual void render(sf::RenderTarget *target);

  private: // functions
	// +--------------+
	// | Initializers |
	// +--------------+
	void initVariables();

  protected: // variables
	MoveDir direction;
	
	int moveState;
	float movementCounter;
	float counter;

	bool turning;
	bool moving;

	sf::Sprite sprite;
};

#endif
