#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML\Graphics.hpp>

class Animation {
  // +------------------+
  // | Public functions |
  // +------------------+
  public:
	Animation(sf::Texture *texture, sf::Vector2u imageCount, float switchTime);
	virtual ~Animation();

	void Update(int row, float deltaTime, bool idle);

  // +------------------+
  // | Public variables |
  // +------------------+
  public:
	sf::IntRect uvRect;

  // +-------------------+
  // | Private variables |
  // +-------------------+
  private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};

#endif
