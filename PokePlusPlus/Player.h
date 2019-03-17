#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity {
  public: // functions
	// +--------------------------+
	// | Constructor / Destructor |
	// +--------------------------+
	Player();
	virtual ~Player();

	// +-----------+
	// | Functions |
	// +-----------+
	void retur() { };

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
