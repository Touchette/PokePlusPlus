#pragma once

#ifndef BUTTON_H
#define BUTTON_H

#include <vector>
#include <sstream>
#include <cstdlib>
#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Button {
  public: // functions
	// +--------------------------+
	// | Constructor / Destructor |
	// +--------------------------+
	Button(float x, float y, float width, float height, std::string text, sf::Font *font, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	virtual ~Button();

	// +-----------+
	// | Functions |
	// +-----------+
	void render(sf::RenderTarget *target);
	void update(bool highlighted);

	// +-------------------+
	// | Getters & Setters |
	// +-------------------+
	const bool isPressed() const;

  private: // functions

  private: // variables
	bool selected;

	sf::RectangleShape shape;
	sf::RectangleShape cursor;
	sf::Font *font;
	sf::Text text;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;
};

#endif
