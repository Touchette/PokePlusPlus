#include "Animation.h"

Animation::Animation(sf::Texture *texture, sf::Vector2u imageCount, float switchTime) {
	this->imageCount = imageCount;
	this->switchTime = switchTime;

	totalTime = 0.0f;
	currentImage.x = 0;

	uvRect.width  = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);
}


Animation::~Animation() {
	// Empty destructor
}

void Animation::Update(int row, float deltaTime, bool idle) {
	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime) {
		totalTime -= switchTime;

		if (idle) {
			currentImage.x = 0;
		}
		else {
			currentImage.x++;
		}

		// Make sure that the animation does not go past how many
		// sprites we have
		if (currentImage.x >= imageCount.x) {
			currentImage.x = 0;
		}

		uvRect.left = currentImage.x * uvRect.width;
		uvRect.top  = currentImage.y * uvRect.height;
	} 
}
