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

	// +-----------+
	// | Functions |
	// +-----------+
	virtual void move(MoveDir dir);
	virtual void startMovement(MoveDir dir);
	virtual void stopMove();
	 
	virtual void update(const float &dt);
	virtual void render(sf::RenderTarget *target);

	// +-------------------+
	// | Getters & Setters |
	// +-------------------+
	virtual void setPosition(const float x, const float y);
	sf::Vector2f getPosition();
	int getDirection(MoveDir dir);

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
	sf::Vector2f lastPosition;

	sf::Sprite sprite;
};

#endif
