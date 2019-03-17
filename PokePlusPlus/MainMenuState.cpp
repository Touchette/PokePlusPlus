#include "MainMenuState.h"


// +--------------------------+
// | Constructor / Destructor |-
MainMenuState::MainMenuState(sf::RenderWindow *window, sf::View *view, std::map<std::string, int> *supportedKeys, std::stack<State *> *states)
	: State(window, view, supportedKeys, states) {
	this->initVariables();
	this->initBackground();
	this->initKeybinds();
	this->initFonts();
	this->initButtons();

	this->currentSelection = "GAMESTATE";
}

MainMenuState::~MainMenuState() {
	// Clean up the buttons
	auto it = this->buttons.begin();
	for (; it != this->buttons.end(); ++it) {
		delete it->second;
	}
}


// +------------------------+
// | Pure Virtual Functions |
// +------------------------+
void MainMenuState::update(const float &dt) {
	// We always pass deltaTime into these functions to keep
	// the framerate and tickrate consistent across all computers
	this->updateInput(dt);
	this->updateButtons();
}

void MainMenuState::render(sf::RenderTarget *target) {
	// Make sure that the primary rendering target is the main window
	if (!target) {
		target = this->window;
	}

	target->draw(this->background);
	this->renderButtons(target);
}

void MainMenuState::renderButtons(sf::RenderTarget *target) {
	for (auto item : this->buttons) {
		item.second->render(target);
	}
}

void MainMenuState::updateInput(const float &dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))) && currentSelection == "GAMESTATE") {
		this->currentSelection = "OPTIONS";
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))) && currentSelection == "OPTIONS") {
		this->currentSelection = "GAMESTATE";
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("ENTER")))) {
		if (currentSelection == "GAMESTATE") {
			this->states->push(new GameState(this->window, this->windowView, this->supportedKeys, this->states));
		}
		if (currentSelection == "OPTIONS") {
			this->endState();
		}
	}
}

void MainMenuState::updateButtons() {
	for (auto item : this->buttons) {
		if (item.first == currentSelection) {
			item.second->update(true);
		} else {
			item.second->update(false);
		}
	}
}


// +--------------+
// | Initializers |
// +--------------+
void MainMenuState::initVariables() {
	//
}

void MainMenuState::initKeybinds() {
	std::ifstream keys("Settings/mainmenu_keybinds.ini");

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

void MainMenuState::initBackground() {
	this->background.setSize(
		sf::Vector2f(
			static_cast<float>(this->window->getSize().x),
			static_cast<float>(this->window->getSize().y)
		)
	);

	if (!this->backgroundTexture.loadFromFile("Sprites/main-menu.png")) {
		std::cerr << "Failed to load Main Menu background texture!" << std::endl;
		exit(EXIT_FAILURE);
	}

	this->background.setTexture(&this->backgroundTexture);
}

void MainMenuState::initFonts() {
	// Load the Pokemon Red font... Not all characters, might have to make
	// some of them
	if (!this->font.loadFromFile("Fonts/PKMN_RBYGSC.ttf")) {
		std::cerr << "Could not load the game font!" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void MainMenuState::initButtons() {
	this->buttons["GAMESTATE"] = new Button(
		27, 30, 100, 20,
		"NEW   GAME", &this->font,
		sf::Color(0, 0, 0, 0), sf::Color(0, 0, 0, 0), sf::Color(0, 0, 0, 0));

	this->buttons["OPTIONS"] = new Button(
		17, 55, 100, 20,
		"OPTION", &this->font,
		sf::Color(0, 0, 0, 0), sf::Color(0, 0, 0, 0), sf::Color(0, 0, 0, 0));
}

