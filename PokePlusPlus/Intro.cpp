#pragma once

#include <iostream>
#include "Intro.h"

// +------------+
// | Animations |
// +------------+

Intro::Intro() {
	//
}

Intro::~Intro() {
	// Empty destructor
}

void Intro::update(float deltaTime) {
	copyrightAnim.update(0, deltaTime);
	screen.setTextureRect(copyrightAnim.uvRect);
	gameFreakLogoAnim.update(0, deltaTime);
	screen.setTextureRect(gameFreakLogoAnim.uvRect);
}

void Intro::play(sf::RenderWindow &window) {
	if (!played) {
		window.draw(screen);
	}
}