#ifndef PLAYER_H
#define PLAYER_H

#include <SFML\Graphics.hpp>
#include "Animation.h"

class Player {
  // +------------------+
  // | Public functions |
  // +------------------+
  public:
	Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed);
	virtual ~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow &window);

  // +-------------------+
  // | Private variables |
  // +-------------------+
  private:
	  unsigned int row, lastRow = 0;
	  float speed = 0.0f;
	  bool idle = true;
	  sf::RectangleShape body;
	  sf::Keyboard::Key lastKey;
	  Animation animation;
};

#endif
