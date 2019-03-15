#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player : public Character {
  // +------------------+
  // | Public functions |
  // +------------------+
  public:
	// =========================+
	// Constructor & Destructor |
	// =========================+
	Player(sf::Texture *texture, sf::Vector2u imageCount);
	virtual ~Player();

	// ======================+
	// Drawing               |
	// ======================+
	void update();
};

#endif
