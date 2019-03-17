#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity {
  public: // functions
	// +--------------------------+
	// | Constructor / Destructor |
	// +--------------------------+
	Player(float x, float y, sf::Texture &texture);
	virtual ~Player();

	// +-----------+
	// | Functions |
	// +-----------+
	void update(const float & dt);

  private: // functions
	// +--------------+
	// | Initializers |
	// +--------------+
	void initVariables();
	void initComponents();

  private: // variables
	//
};

#endif
