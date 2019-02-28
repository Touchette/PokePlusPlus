#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char *argv[]) {
	sf::RenderWindow window(sf::VideoMode(512, 512), "PokéPlusPlus", sf::Style::Close | sf::Style::Titlebar);

	sf::Image icon;
	if (!icon.loadFromFile("../Sprites/icon.png")) {
		std::cout << "Could not load file!" << std::endl;
		return 1;
	} else { // set the window icon
		const sf::Uint8 *iconPixels = icon.getPixelsPtr();
		window.setIcon(12, 12, iconPixels);
	}

	// Main window loop
	while (window.isOpen()) {
		sf::Event evnt;

		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
				case sf::Event::Closed: 
					window.close();
					break;
			}
		}
	}

	return 0;
}