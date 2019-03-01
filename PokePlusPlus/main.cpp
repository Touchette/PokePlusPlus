#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

int main(int argc, char *argv[]) {
	// Set up the window
	int height, width;
	height = 416; width = 480;
	sf::RenderWindow window(sf::VideoMode(width, height), "PokéPlusPlus", sf::Style::Close | sf::Style::Titlebar);

	sf::Image icon;
	if (!icon.loadFromFile("Sprites/icon.png")) {
		std::cout << "Could not load file!" << std::endl;
		return 1;
	}
	else { // set the window icon
		const sf::Uint8 *iconPixels = icon.getPixelsPtr();
		window.setIcon(12, 12, iconPixels);
	}

	// Draw the background
	sf::RectangleShape background(sf::Vector2f(480.0f, 416.0f));
	sf::Texture starterTown;

	starterTown.loadFromFile("Sprites/littleroot-town-global.png");

	background.setTexture(&starterTown);

	// 0, 1, 2 in x    : 0 is walk left, 1 is walk straight, 2 is walk right
	// 0, 1, 2, 3 in y : 0 is forward, 1 is right, 2 is back, 3 is left
	sf::Texture playerTexture;
	playerTexture.loadFromFile("Sprites/may-walk-cycles.png");

	Player player(&playerTexture, sf::Vector2u(3, 4), 0.18f, 40.0f);

	float deltaTime = 0.0f;
	sf::Clock clock;

	// Main window loop
	while (window.isOpen()) {
		deltaTime = clock.restart().asSeconds();

		sf::Event evnt;

		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
				case sf::Event::Closed: 
					window.close();
					break;
			}
		}
		player.Update(deltaTime);

		window.clear();
		window.draw(background);
		player.Draw(window);
		window.display();
	}

	return 0;
}