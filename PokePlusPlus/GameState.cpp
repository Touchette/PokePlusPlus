#include "GameState.h"


// +--------------------------+
// | Constructor / Destructor |
// +--------------------------+
GameState::GameState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys) 
	: State(window, supportedKeys) {
	this->initKeybinds();
}


GameState::~GameState() {
	//
}


// +------------------------+
// | Pure Virtual Functions |
// +------------------------+
void GameState::update(const float &dt) {
	this->updateInput(dt);

	this->player.update(dt);
}

void GameState::render(sf::RenderTarget *target) {

	if (!target) {
		target = this->window;
	}
	this->player.render(this->window);
}

void GameState::endState() {
	std::cout << "Ending game state\n";
}

void GameState::updateInput(const float &dt) {
	// Update the player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP")))) {
		this->player.move(dt, 0.0f, -1.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN")))) {
		this->player.move(dt, 0.0f, 1.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT")))) {
		this->player.move(dt, -1.0f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT")))) {
		this->player.move(dt, 1.0f, 0.0f);
	}

	this->checkForQuit();
}

void GameState::initKeybinds() {
	this->keybinds.emplace("MOVE_UP", this->supportedKeys->at("Up"));
	this->keybinds.emplace("MOVE_DOWN", this->supportedKeys->at("Down"));
	this->keybinds.emplace("MOVE_LEFT", this->supportedKeys->at("Left"));
	this->keybinds.emplace("MOVE_RIGHT", this->supportedKeys->at("Right"));
}
