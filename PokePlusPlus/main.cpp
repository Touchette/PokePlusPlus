#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char *argv[]) {
	sf::RenderWindow window(sf::VideoMode(256, 256), "PokéPlusPlus", sf::Style::Close | sf::Style::Titlebar);

	sf::RectangleShape player(sf::Vector2f(14.0f, 20.0f));
	sf::Texture MayIdleTexture;
	sf::Texture MayLeftTexture;
	sf::Texture MayRightTexture;
	sf::Texture MayBackTexture;
	MayIdleTexture.loadFromFile("../Sprites/may-idle-forward.png");
	MayLeftTexture.loadFromFile("../Sprites/may-idle-left.png");
	MayRightTexture.loadFromFile("../Sprites/may-idle-right.png");
	MayBackTexture.loadFromFile("../Sprites/may-idle-back.png");
	player.setTexture(&MayIdleTexture);

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
				case sf::Event::TextEntered:
					if (evnt.text.unicode < 128) {
						//printf("%c", evnt.text.unicode);
					}
					break;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			player.setTexture(&MayBackTexture);
			player.move(sf::Vector2f(0, -0.01f));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			player.setTexture(&MayLeftTexture);
			player.move(sf::Vector2f(-0.01f, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			player.setTexture(&MayIdleTexture);
			player.move(sf::Vector2f(0, 0.01f));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			player.setTexture(&MayRightTexture);
			player.move(sf::Vector2f(0.01f, 0));
		}

		window.clear();
		window.draw(player);
		window.display();
	}

	return 0;
}