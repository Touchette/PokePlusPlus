#include "MainMenuState.h"


// +--------------------------+
// | Constructor / Destructor |
// +--------------------------+
MainMenuState::MainMenuState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys)
	: State(window, supportedKeys) {
	this->initKeybinds();

	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Magenta);
}


MainMenuState::~MainMenuState() {
	//
}


// +------------------------+
// | Pure Virtual Functions |
// +------------------------+
void MainMenuState::update(const float &dt) {
	this->updateInput(dt);
}

void MainMenuState::render(sf::RenderTarget *target) {
	if (!target) {
		target = this->window;
	}

	target->draw(this->background);
}

void MainMenuState::endState() {
	std::cout << "Ending game state\n";
}

void MainMenuState::updateInput(const float &dt) {
	this->checkForQuit();
}

void MainMenuState::initKeybinds() {
	std::ifstream keys("Settings/gamestate_keybinds.ini");

	// Initialize the keybindings from a file instead of hard
	// coding it, just reads them into a dictionary
	if (keys.is_open()) {
		std::string key = "";
		std::string key_value = "";

		while (keys >> key >> key_value) {
			this->keybinds[key] = this->supportedKeys->at(key_value);
		}
	}

	keys.close();
}

